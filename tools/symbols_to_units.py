#!/usr/bin/env python3
"""symbols_to_units.py - da export Ghidra a unit di matching per-funzione.

Prende symbols.json (tools/ghidra/analyze_amiga.py), ritaglia ogni funzione
dal dump degli hunk (orig/) in orig/func/<nome>.bin e (ri)genera
config/units.json. Genera anche include/amiga_lvo.h dalla tabella LVO.

Ipotesi di caricamento: hunk in sequenza da --base (stessa di split_hunk.py;
il manifest orig/manifest.json, se presente, fa fede).

Uso:
    python tools/symbols_to_units.py --symbols symbols.json --orig-dir orig
    python tools/symbols_to_units.py --self-test
"""

import argparse
import importlib.util
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_DATA = os.path.join(HERE, "ghidra", "amiga_data.json")


def sanitize(name):
    s = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if not s or s[0].isdigit():
        s = "f_" + s
    return s


def load_manifest(orig_dir, manifest_path, base):
    if manifest_path and os.path.isfile(manifest_path):
        with open(manifest_path, encoding="utf-8") as f:
            man = json.load(f)
        hunks = []
        for h in man["hunks"]:
            hunks.append({"hunk": h["hunk"], "type": h["type"],
                          "file": h["file"], "size": h["size"],
                          "base": int(h["base"], 16)})
        return hunks
    # fallback: ricostruisci da orig/hunkN_* in sequenza
    files = sorted(f for f in os.listdir(orig_dir)
                   if re.match(r"hunk\d+_(CODE|DATA)\.bin", f))
    hunks = []
    addr = base
    for fn in files:
        m = re.match(r"hunk(\d+)_(CODE|DATA)\.bin", fn)
        size = os.path.getsize(os.path.join(orig_dir, fn))
        hunks.append({"hunk": int(m.group(1)), "type": m.group(2),
                      "file": os.path.join(orig_dir, fn),
                      "size": size, "base": addr})
        addr += (size + 3) & ~3
    return hunks


def find_hunk(hunks, addr, size):
    for h in hunks:
        if h["type"] == "BSS":
            continue
        if h["base"] <= addr and addr + size <= h["base"] + h["size"]:
            with open(h["file"], "rb") as f:
                data = f.read()
            return h, data[addr - h["base"]:addr - h["base"] + size]
    return None, None


def convert(symbols_path, orig_dir, func_dir, out_units, manifest_path,
            base, lvo_header, data_path, src_dir="src", asm_dir="asm",
            build_dir="build"):
    with open(symbols_path, encoding="utf-8") as f:
        syms = json.load(f)
    hunks = load_manifest(orig_dir, manifest_path, base)
    if not hunks:
        print("nessun hunk in %s (fai prima make split)" % orig_dir,
              file=sys.stderr)
        return 1
    os.makedirs(func_dir, exist_ok=True)

    # preserva flag 'complete' esistenti
    prev_complete = {}
    if os.path.isfile(out_units):
        try:
            prev = json.load(open(out_units, encoding="utf-8"))
            for u in prev.get("units", []):
                prev_complete[u["name"]] = bool(u.get("complete", False))
        except Exception:
            pass

    units, skipped, seen = [], [], set()
    for fn in syms.get("functions", []):
        name = fn["name"]
        if fn.get("external") or fn.get("thunk"):
            skipped.append((name, "external/thunk"))
            continue
        addr, size = int(fn["address"], 16), int(fn.get("size", 0))
        if size <= 0:
            skipped.append((name, "size 0"))
            continue
        h, blob = find_hunk(hunks, addr, size)
        if h is None:
            skipped.append((name, "fuori dagli hunk (ROM?)"))
            continue
        uname = sanitize(name)
        if uname in seen:
            uname = "%s_%x" % (uname, addr)
        seen.add(uname)
        with open(os.path.join(func_dir, uname + ".bin"), "wb") as f:
            f.write(blob)
        if os.path.isfile(os.path.join(src_dir, uname + ".c")):
            src = os.path.join(src_dir, uname + ".c")
        elif os.path.isfile(os.path.join(asm_dir, uname + ".s")):
            src = os.path.join(asm_dir, uname + ".s")
        else:
            src = os.path.join(src_dir, uname + ".c")  # da scrivere
        units.append({
            "name": uname,
            "target": os.path.join(func_dir, uname + ".bin").replace(os.sep, "/"),
            "base": os.path.join(build_dir, uname + ".o").replace(os.sep, "/"),
            "source_path": src.replace(os.sep, "/"),
            "complete": prev_complete.get(uname, False),
            "progress_categories": ["code"],
        })
    units.sort(key=lambda u: u["name"])

    os.makedirs(os.path.dirname(os.path.abspath(out_units)), exist_ok=True)
    with open(out_units, "w", encoding="utf-8") as f:
        json.dump({"units": units}, f, indent=2)

    if lvo_header:
        write_lvo_header(data_path, lvo_header)

    print("funzioni -> %d unit (%d saltate) in %s" % (len(units), len(skipped), out_units))
    for name, why in skipped:
        print("  skip %-24s %s" % (name, why))
    return 0


def write_lvo_header(data_path, out_path):
    with open(data_path, encoding="utf-8") as f:
        data = json.load(f)
    lvo = data.get("exec_lvo", {})
    lines = ["#ifndef AMIGA_LVO_H", "#define AMIGA_LVO_H", "",
             "/* Offset vettori Exec (A6) per chiamate AmigaOS.",
             " * Generato da tools/symbols_to_units.py <- amiga_data.json.",
             " * Verificati contro NDK (exec_lib.fd dell'estensione ghidra-amiga).",
             " * Per altre librerie (dos/graphics/intuition) usare i .fd in",
             " * <ghidra-amiga>/data/fd/ allo stesso modo. */", ""]
    for name in sorted(lvo):
        lines.append("#define _LVO%s %d" % (name, lvo[name]))
    lines += ["", "#endif /* AMIGA_LVO_H */", ""]
    os.makedirs(os.path.dirname(os.path.abspath(out_path)), exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print("header LVO: %s (%d define)" % (out_path, len(lvo)))


def _load_diff():
    spec = importlib.util.spec_from_file_location(
        "diff_m68k", os.path.join(HERE, "diff_m68k.py"))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def self_test():
    import tempfile
    print("== symbols_to_units.py self-test ==")
    sys.path.insert(0, HERE)
    import split_hunk
    diff = _load_diff()
    with tempfile.TemporaryDirectory() as d:
        orig = os.path.join(d, "orig")
        os.makedirs(orig)
        exe = os.path.join(d, "game.exe")
        open(exe, "wb").write(split_hunk.make_test_exe())
        man_path = os.path.join(orig, "manifest.json")
        split_hunk.split_to_dir(exe, orig, manifest_path=man_path, base_addr=0x1000)
        syms = {"program": "game.exe", "functions": [
            {"name": "func_a", "address": "0x1000", "size": 2},
            {"name": "WaitRaster", "address": "0x1002", "size": 2},
            {"name": "ROMCall", "address": "0xF80000", "size": 4},
            {"name": "ext", "address": "0x0", "size": 4, "external": True},
            {"name": "empty", "address": "0x1000", "size": 0},
        ]}
        sp = os.path.join(d, "symbols.json")
        json.dump(syms, open(sp, "w"))
        func_dir = os.path.join(orig, "func")
        bd = os.path.join(d, "build")
        os.makedirs(bd)
        out_units = os.path.join(d, "units.json")
        lvo_h = os.path.join(d, "amiga_lvo.h")
        rc = convert(sp, orig, func_dir, out_units, man_path, 0x1000,
                     lvo_h, DEFAULT_DATA, build_dir=bd)
        assert rc == 0
        # 1. slice corretti: CODE = NOP RTS
        assert open(os.path.join(func_dir, "func_a.bin"), "rb").read() == bytes.fromhex("4e71")
        assert open(os.path.join(func_dir, "WaitRaster.bin"), "rb").read() == bytes.fromhex("4e75")
        print("  [ok] slice per-funzione corretti")
        # 2. skip: ROM + external + size0
        units = json.load(open(out_units))["units"]
        assert [u["name"] for u in units] == ["WaitRaster", "func_a"], units
        assert os.path.basename(units[0]["base"]) == "WaitRaster.o"
        print("  [ok] 2 unit, 3 skip (ROM/external/size0)")
        # 3. header LVO generato
        h = open(lvo_h).read()
        assert "#define _LVOOpenLibrary -552" in h and "#define _LVOAllocMem -198" in h, h
        print("  [ok] amiga_lvo.h con LVO Exec")
        # 4. integrazione col diff: 0 implementate -> 0%; 1 copiata -> 50% func
        rep0 = diff.build_report(diff.load_units(orig, bd, out_units))
        assert rep0["measures"]["matched_functions"] == 0, rep0["measures"]
        open(os.path.join(bd, "func_a.o"), "wb").write(bytes.fromhex("4e71"))
        rep1 = diff.build_report(diff.load_units(orig, bd, out_units))
        m = rep1["measures"]
        assert (m["matched_functions"], m["total_functions"]) == (1, 2), m
        assert m["matched_code"] == 2 and m["total_code"] == 4, m
        print("  [ok] integrazione diff: 0%% -> 1/2 func, 2/4 byte")
        # 5. rigenerazione preserva 'complete'
        units[0]["complete"] = True
        json.dump({"units": units}, open(out_units, "w"))
        convert(sp, orig, func_dir, out_units, man_path, 0x1000, None, DEFAULT_DATA)
        units2 = {u["name"]: u for u in json.load(open(out_units))["units"]}
        assert units2["WaitRaster"]["complete"] is True
        print("  [ok] flag complete preservati alla rigenerazione")
    print("ALL SELF-TESTS PASSED")


def main(argv=None):
    ap = argparse.ArgumentParser(description="Ghidra symbols.json -> units.json per-funzione")
    ap.add_argument("--symbols", default="symbols.json")
    ap.add_argument("--orig-dir", default="orig")
    ap.add_argument("--func-dir", default="orig/func")
    ap.add_argument("--out-units", default="config/units.json")
    ap.add_argument("--manifest", default="orig/manifest.json")
    ap.add_argument("--base", default="0x0")
    ap.add_argument("--lvo-header", default="include/amiga_lvo.h")
    ap.add_argument("--data", default=DEFAULT_DATA)
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        self_test()
        return 0
    return convert(a.symbols, a.orig_dir, a.func_dir, a.out_units,
                   a.manifest, int(a.base, 16), a.lvo_header, a.data)


if __name__ == "__main__":
    sys.exit(main())
