#!/usr/bin/env python3
"""agent/loop.py - ciclo Decompile -> Compile -> Diff -> Refine per unit M68k.

Per ogni unit non al 100%: genera varianti C (euristiche, +LLM se configurato),
le compila col toolchain, tiene la migliore per byte matchati. Idempotente:
non peggiora mai il risultato esistente (stato in <work>/state.json).

Uso:
    python tools/agent/loop.py --units config/units.json
    python tools/agent/loop.py --backend llm --iters 5   # richiede OPENAI_API_KEY
    python tools/agent/loop.py --self-test               # fake toolchain, no rete
"""

import argparse
import hashlib
import json
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, ".."))
import diff_m68k  # noqa: E402
import backends  # noqa: E402  (stessa dir, in sys.path come script)


def sh(cmd, timeout):
    p = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=timeout)
    return p.returncode, (p.stdout or "") + (p.stderr or "")


def score_bytes(target, built):
    matched, total, _ = diff_m68k.compare_bytes(target, built if built else b"")
    return (matched / total) if total else 1.0, matched, total


def skeleton_c(name, target):
    lines = backends.disasm_lines(target)
    body = "\n".join("    /* %s */" % l for l in lines)
    return ("/* %s: skeleton dal disassembly, da decompilare */\n"
            "void %s(void) {\n%s\n}\n" % (name, name, body))


def fake_step_variants(candidate_c, target, it, mode="improve"):
    """SOLO TEST: 'improve' emette prefissi crescenti del target,
    'worsen' solo byte 0xFF (mai meglio dell'esistente)."""
    out = []
    steps = (len(target) // 2, len(target)) if mode == "improve" else (len(target),)
    for k in steps:
        if mode == "improve":
            blob = target[:k].hex()
        else:
            blob = "00" * len(target)  # != dal target del test (ff..ff)
        src = candidate_c + "\n/* FAKE-EMIT: %s */\n" % blob
        out.append(("fake-%s k=%d (iter %d)" % (mode, k, it), src, ""))
    return out


def run_unit(u, target, cfg, dirs, state, backend, iters, fake=False):
    name = u["name"]
    base_rel = u["base"]
    base_abs = base_rel if os.path.isabs(base_rel) else os.path.join(dirs["root"], base_rel)
    cur_built = open(base_abs, "rb").read() if os.path.isfile(base_abs) else b""
    best_score, best_matched, total = score_bytes(target, cur_built)
    best_src = None
    prev = state.get(name, {})
    if best_score >= 1.0:
        print("  %-20s 100%%, skip" % name)
        return True

    src_path = None
    for cand in (os.path.join(dirs["src"], name + ".c"),
                 os.path.join(dirs["decompiled"], name + ".c")):
        if os.path.isfile(cand):
            src_path = cand
            break
    candidate = open(src_path, encoding="utf-8").read() if src_path else skeleton_c(name, target)

    improved = False
    for it in range(max(1, iters)):
        if fake:
            variants = fake_step_variants(candidate, target, it,
                                          mode="improve" if fake is True else fake)
        else:
            variants = backends.heuristic_variants(
                candidate, cfg.get("flag_sets", [""]), cfg.get("max_variants_per_unit", 8))
            if backend == "llm":
                for prop in backends.llm_proposals(
                        candidate, target, cur_built, best_score * 100.0, cfg.get("llm", {})):
                    variants.append(("llm", prop, ""))
        for label, src, flags in variants:
            tmp_c = os.path.join(dirs["work"], name + ".cand.c")
            tmp_o = os.path.join(dirs["work"], name + ".cand.o")
            with open(tmp_c, "w", encoding="utf-8") as f:
                f.write(src)
            cmd = cfg["compile_c"].format(root=dirs["root"], src=tmp_c, out=tmp_o, flags=flags)
            try:
                rc, log = sh(cmd, cfg.get("compile_timeout", 300))
            except subprocess.TimeoutExpired:
                print("  %-20s %-28s TIMEOUT" % (name, label))
                continue
            if rc != 0 or not os.path.isfile(tmp_o):
                continue
            built = open(tmp_o, "rb").read()
            sc, matched, _ = score_bytes(target, built)
            if sc > best_score:
                best_score, best_matched = sc, matched
                best_src = src
                cur_built = built
                improved = True
                print("  %-20s %-28s -> %.1f%% (%d/%d)" % (name, label, sc * 100, matched, total))
        if best_score >= 1.0:
            break
    if improved:
        os.makedirs(os.path.dirname(os.path.abspath(base_abs)), exist_ok=True)
        open(base_abs, "wb").write(cur_built)
        out_src = os.path.join(dirs["src"], name + ".c")
        os.makedirs(os.path.dirname(os.path.abspath(out_src)), exist_ok=True)
        with open(out_src, "w", encoding="utf-8") as f:
            f.write(best_src)
        state[name] = {"score": round(best_score, 4),
                       "sha": hashlib.sha256(best_src.encode()).hexdigest()[:16]}
    else:
        print("  %-20s nessun miglioramento (resta %.1f%%)" % (name, best_score * 100))
        state.setdefault(name, prev)
    return improved


def main(argv=None):
    ap = argparse.ArgumentParser(description="Agent matching M68k: compile/diff/refine loop")
    ap.add_argument("--units", default="config/units.json")
    ap.add_argument("--target-dir", default="orig")
    ap.add_argument("--build-dir", default="build")
    ap.add_argument("--src-dir", default="src")
    ap.add_argument("--decompiled-dir", default="decompiled")
    ap.add_argument("--work", default="agent/work")
    ap.add_argument("--config", default="tools/agent/config.json")
    ap.add_argument("--backend", choices=["heuristic", "llm"], default=None)
    ap.add_argument("--iters", type=int, default=None)
    ap.add_argument("--only", default=None, help="solo questa unit (nome)")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()

    cfg = json.load(open(a.config, encoding="utf-8"))
    backend = a.backend or cfg.get("backend", "heuristic")
    iters = a.iters if a.iters is not None else cfg.get("max_iters", 3)
    root = os.path.abspath(os.getcwd())
    dirs = {"root": root, "src": a.src_dir, "decompiled": a.decompiled_dir,
            "work": a.work}
    os.makedirs(a.work, exist_ok=True)
    state_path = os.path.join(a.work, "state.json")
    state = json.load(open(state_path, encoding="utf-8")) if os.path.isfile(state_path) else {}

    units = diff_m68k.load_units(a.target_dir, a.build_dir, a.units)
    if a.only:
        units = [u for u in units if u["name"] == a.only]
    print("agent: %d unit, backend=%s, iters=%d" % (len(units), backend, iters))
    improved = 0
    for u in units:
        tp = u["target"]
        if not tp or not os.path.isfile(tp):
            continue
        target = open(tp, "rb").read()
        if run_unit(u, target, cfg, dirs, state, backend, iters):
            improved += 1
    json.dump(state, open(state_path, "w", encoding="utf-8"), indent=2)
    print("migliorate: %d/%d (stato: %s)" % (improved, len(units), state_path))
    return 0


def self_test():
    import tempfile
    print("== agent/loop.py self-test ==")
    with tempfile.TemporaryDirectory() as d:
        target = bytes.fromhex("4e56fff833c000dff1804e5e4e75")
        open(os.path.join(d, "t.bin"), "wb").write(target)
        units_p = os.path.join(d, "units.json")
        json.dump({"units": [{"name": "entry", "target": os.path.join(d, "t.bin"),
                              "base": os.path.join(d, "build", "entry.o"),
                              "complete": False}]}, open(units_p, "w"))
        cfg = {"compile_c": '"%s" "%s" {src} {out}' % (
                 sys.executable, os.path.join(HERE, "fake_cc.py")),
               "flag_sets": [""], "max_variants_per_unit": 4,
               "compile_timeout": 60}
        dirs = {"root": d, "src": os.path.join(d, "src"),
                "decompiled": os.path.join(d, "dec"), "work": os.path.join(d, "work")}
        for k in ("src", "decompiled", "work", "build"):
            os.makedirs(os.path.join(d, k))
        state = {}
        u = json.load(open(units_p))["units"][0]
        # 1. converge a 100%
        assert run_unit(u, target, cfg, dirs, state, "heuristic", 2, fake=True) is True
        assert state["entry"]["score"] == 1.0, state
        assert open(os.path.join(d, "build", "entry.o"), "rb").read() == target
        assert os.path.isfile(os.path.join(d, "src", "entry.c"))
        print("  [ok] converge 0%% -> 100%%, scrive src+obj+stato")
        # 2. idempotente: seconda run = skip, nessun peggioramento
        assert run_unit(u, target, cfg, dirs, state, "heuristic", 2, fake=True) is True
        assert open(os.path.join(d, "build", "entry.o"), "rb").read() == target
        print("  [ok] idempotente al 100%")
        # 3. senza miglioramento possibile non tocca nulla
        bad = bytes.fromhex("ffffffff")
        open(os.path.join(d, "t2.bin"), "wb").write(bad)
        u2 = dict(u, name="stuck", target=os.path.join(d, "t2.bin"),
                  base=os.path.join(d, "build", "stuck.o"))
        open(os.path.join(d, "build", "stuck.o"), "wb").write(bytes.fromhex("ffffff00"))
        before = open(os.path.join(d, "build", "stuck.o"), "rb").read()  # 75% vs target
        assert run_unit(u2, bad, cfg, dirs, state, "heuristic", 1, fake="worsen") is False
        assert open(os.path.join(d, "build", "stuck.o"), "rb").read() == before
        print("  [ok] mai peggiora l'esistente")
        # 4. LLM senza chiave -> [] senza rete
        assert backends.llm_proposals("x", b"y", b"z", 0.0, {}) == []
        print("  [ok] llm senza API key = fallback silenzioso")
        # 5. euristiche generano varianti compilabili (flag x qualifier)
        vs = backends.heuristic_variants("int x; volatile CUSTOM c;", ["", "-O1"], 8)
        assert len(vs) == 4 and all(v[1].strip() for v in vs), vs
        print("  [ok] 2 flag x 2 qualifier = 4 varianti")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
