#!/usr/bin/env python3
"""diff_m68k.py - binary matching per decomp Amiga M68k.

Confronta gli oggetti ricompilati (build/) con quelli originali (orig/) e
genera un report.json compatibile con decomp.dev (REPORT_VERSION = 2, cfr.
objdiff-core/protos/report.proto).

Perche' non objdiff: objdiff-core/src/arch/mod.rs supporta solo
arm, arm64, mips, ppc, superh, x86. M68k non e' supportato, quindi il
matching e' fatto qui (byte-perfect + disassembly M68k via capstone).

Uso:
    python tools/diff_m68k.py --target-dir orig --build-dir build -o build/report.json
    python tools/diff_m68k.py --self-test   # test senza toolchain
"""

import argparse
import json
import os
import sys

REPORT_VERSION = 2

try:
    from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN

    def _disasm_mnemonics(data: bytes):
        md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
        md.detail = False
        try:
            return [i.mnemonic for i in md.disasm(data, 0x0)]
        except Exception:
            return []
except Exception:
    def _disasm_mnemonics(data: bytes):
        return []


def load_units(target_dir, build_dir, units_file):
    """Ritorna lista di dict {name, target, base, ...}."""
    if units_file and os.path.isfile(units_file):
        with open(units_file, "r", encoding="utf-8") as f:
            cfg = json.load(f)
        units = []
        for u in cfg.get("units", []):
            units.append({
                "name": u["name"],
                "target": u.get("target"),
                "base": u.get("base"),
                "source_path": u.get("source_path"),
                "complete": bool(u.get("complete", False)),
                "progress_categories": list(u.get("progress_categories", [])),
            })
        return units
    # Auto-discover: ogni file in build_dir accoppiato con omonimo in target_dir
    units = []
    for root, _, files in os.walk(build_dir):
        for fn in sorted(files):
            if fn == "report.json":
                continue
            base = os.path.join(root, fn)
            rel = os.path.relpath(base, build_dir)
            target = os.path.join(target_dir, rel)
            name = os.path.splitext(rel.replace(os.sep, "/"))[0]
            units.append({"name": name, "target": target, "base": base,
                          "source_path": None, "complete": False,
                          "progress_categories": []})
    return units


def hunk_unit_payload(data: bytes):
    """Estrae i byte CODE/DATA da un oggetto Hunk (vc/vasm -Fhunk).

    Ritorna i payload concatenati, o None se non e' Hunk (file raw).
    Necessario perche' gli oggetti hanno header: il confronto per il
    matching va fatto sui payload, non sui file interi.
    """
    import struct
    if len(data) < 4:
        return None
    if struct.unpack_from(">I", data, 0)[0] & 0x3FFFFFFF != 0x3E7:
        return None  # non HUNK_UNIT -> raw
    out = bytearray()
    pos, n = 4, len(data)
    while pos + 8 <= n:
        tag = struct.unpack_from(">I", data, pos)[0] & 0x3FFFFFFF
        if tag in (0x3E9, 0x3EA):  # CODE / DATA
            nlongs = struct.unpack_from(">I", data, pos + 4)[0]
            out += data[pos + 8:pos + 8 + nlongs * 4]
            pos += 8 + nlongs * 4
        else:
            pos += 4
    return bytes(out) if out else None


def _payload(data: bytes):
    p = hunk_unit_payload(data)
    return p if p is not None else data


def _rstrip_pad(payload: bytes, target_len: int):
    """Toglie il padding di allineamento sezione (NOP 4E71 / zeri) in coda
    al payload oltre la lunghezza target. vasm allinea le sezioni a 4 byte.
    Non tocca mai i primi target_len byte."""
    while len(payload) > target_len and payload[-2:] in (b"\x4e\x71", b"\x00\x00"):
        payload = payload[:-2]
    return payload


def compare_bytes(target: bytes, base: bytes):
    """Ritorna (matched_bytes, total, fuzzy_percent).

    total = len(target) (il riferimento e' l'originale).
    matched = byte identici sullo stesso offset.
    fuzzy = disassembly mnemonic match (se capstone disponibile), else = byte ratio.
    """
    total = len(target)
    if total == 0 and len(base) == 0:
        return 0, 0, 100.0
    if total == 0:
        return 0, 0, 0.0
    n = min(len(target), len(base))
    matched = sum(1 for i in range(n) if target[i] == base[i])
    # byte extra/mancanti contano come non-matched (total resta len(target)
    # se base e' piu' lunga, l'eccesso pesa via fuzzy)
    byte_pct = matched / total * 100.0

    t_mnem = _disasm_mnemonics(target)
    b_mnem = _disasm_mnemonics(base)
    if t_mnem and b_mnem:
        m = sum(1 for a, b in zip(t_mnem, b_mnem) if a == b)
        fuzzy = m / max(len(t_mnem), 1) * 100.0
        # penalizza differenza di lunghezza istruzioni
        if len(b_mnem) != len(t_mnem):
            fuzzy *= min(len(b_mnem), len(t_mnem)) / max(len(b_mnem), len(t_mnem))
    else:
        fuzzy = byte_pct
    return matched, total, fuzzy


def measure_unit(u):
    tp, bp = u["target"], u["base"]
    t = open(tp, "rb").read() if tp and os.path.isfile(tp) else None
    b = open(bp, "rb").read() if bp and os.path.isfile(bp) else None

    if t is None and b is None:
        return None  # skip, come objdiff report_object senza target ne base
    if t is None:
        # come objdiff: senza target non c'e' nulla da matchare -> skip con warning
        print(f"warning: target mancante, skip unit '{u['name']}' ({tp})",
              file=sys.stderr)
        return None
    # gli oggetti Hunk (vc/vasm) si confrontano sui payload CODE/DATA
    t = _payload(t)
    b = _payload(b) if b is not None else None
    if b is None:
        b = b""  # target c'e', base manca = funzione non ancora decompilata: 0%
    else:
        b = _rstrip_pad(b, len(t))

    matched, total, fuzzy = compare_bytes(t, b)
    full_match = (matched == total and total > 0)
    if u["complete"] and t is not None and b is None:
        full_match = True  # convenzione objdiff: complete senza base = 100%

    measures = {
        "fuzzy_match_percent": round(fuzzy if full_match else (100.0 if full_match else fuzzy), 2),
        "total_code": total,
        "matched_code": total if full_match else matched,
        "matched_code_percent": 0.0,  # calcolata sotto
        "total_data": 0,
        "matched_data": 0,
        "matched_data_percent": 100.0,
        "total_functions": 1,
        "matched_functions": 1 if full_match else 0,
        "matched_functions_percent": 0.0,
        "complete_code": total if u["complete"] else 0,
        "complete_code_percent": 0.0,
        "complete_data": 0,
        "complete_data_percent": 100.0,
        "total_units": 1,
        "complete_units": 1 if u["complete"] else 0,
    }
    if full_match:
        measures["fuzzy_match_percent"] = 100.0
        measures["matched_code"] = total
    # percentuali
    measures["matched_code_percent"] = round(
        100.0 if total == 0 else measures["matched_code"] / total * 100.0, 2)
    measures["matched_functions_percent"] = round(
        measures["matched_functions"] / 1 * 100.0, 2)
    measures["complete_code_percent"] = round(
        100.0 if total == 0 else measures["complete_code"] / total * 100.0, 2)

    fn_pct = 100.0 if full_match else round(fuzzy, 2)
    unit = {
        "name": u["name"],
        "measures": measures,
        "sections": [{"name": ".text", "size": total,
                      "fuzzy_match_percent": measures["fuzzy_match_percent"]}],
        "functions": [{"name": u["name"], "size": total,
                       "fuzzy_match_percent": fn_pct}],
        "metadata": {"complete": u["complete"],
                     "source_path": u["source_path"],
                     "progress_categories": u["progress_categories"]},
    }
    # ripulisci None (proto optional)
    if u["source_path"] is None:
        del unit["metadata"]["source_path"]
    if not u["progress_categories"]:
        del unit["metadata"]["progress_categories"]
    return unit


def build_report(units):
    measured = [m for m in (measure_unit(u) for u in units) if m is not None]
    total_code = sum(u["measures"]["total_code"] for u in measured)
    matched_code = sum(u["measures"]["matched_code"] for u in measured)
    total_fn = sum(u["measures"]["total_functions"] for u in measured)
    matched_fn = sum(u["measures"]["matched_functions"] for u in measured)
    fuzzy_acc = sum(u["measures"]["fuzzy_match_percent"] * u["measures"]["total_code"]
                    for u in measured)
    measures = {
        "fuzzy_match_percent": round(fuzzy_acc / total_code, 2) if total_code else 100.0,
        "total_code": total_code,
        "matched_code": matched_code,
        "matched_code_percent": round(matched_code / total_code * 100.0, 2) if total_code else 100.0,
        "total_data": 0, "matched_data": 0, "matched_data_percent": 100.0,
        "total_functions": total_fn, "matched_functions": matched_fn,
        "matched_functions_percent": round(matched_fn / total_fn * 100.0, 2) if total_fn else 100.0,
        "complete_code": sum(u["measures"]["complete_code"] for u in measured),
        "complete_code_percent": 0.0,
        "complete_data": 0, "complete_data_percent": 100.0,
        "total_units": len(measured),
        "complete_units": sum(u["measures"]["complete_units"] for u in measured),
    }
    measures["complete_code_percent"] = round(
        measures["complete_code"] / total_code * 100.0, 2) if total_code else 100.0
    return {"measures": measures, "units": measured,
            "version": REPORT_VERSION, "categories": []}


def self_test():
    import struct
    import tempfile
    print("== diff_m68k.py self-test ==")
    # 1. byte-identici -> 100%
    m, t, f = compare_bytes(b"\x4e\x71\x4e\x75", b"\x4e\x71\x4e\x75")
    assert (m, t) == (4, 4) and f == 100.0, (m, t, f)
    print("  [ok] identical -> 100%")
    # 2. un byte diverso su 4 -> 75% matched
    m, t, f = compare_bytes(b"\x4e\x71\x4e\x75", b"\x4e\x71\x4e\x71")
    assert m == 3 and t == 4, (m, t)
    print("  [ok] 1 byte diff -> matched 3/4")
    # 2b. Hunk UNIT sintetico -> payload
    unit = (struct.pack(">I", 0x3E7) + struct.pack(">I", 0)      # UNIT, nome vuoto
            + struct.pack(">II", 0x3E9, 1) + bytes.fromhex("4e714e75")
            + struct.pack(">I", 0x3F2))
    assert hunk_unit_payload(unit) == bytes.fromhex("4e714e75"), \
        hunk_unit_payload(unit)
    assert hunk_unit_payload(bytes.fromhex("4e714e75")) is None
    print("  [ok] payload Hunk UNIT estratto, raw invariato")
    # 2c. padding di sezione (4E71/00) oltre il target non penalizza
    assert _rstrip_pad(bytes.fromhex("4e754e71"), 2) == bytes.fromhex("4e75")
    assert _rstrip_pad(bytes.fromhex("4e750000"), 2) == bytes.fromhex("4e75")
    assert _rstrip_pad(bytes.fromhex("4e71"), 2) == bytes.fromhex("4e71")
    print("  [ok] tolleranza padding di allineamento")
    # 3. report end-to-end con file temporanei
    with tempfile.TemporaryDirectory() as d:
        od, bd = os.path.join(d, "orig"), os.path.join(d, "build")
        os.makedirs(od); os.makedirs(bd)
        open(os.path.join(od, "main.o"), "wb").write(b"\x4e\x71\x4e\x75")
        open(os.path.join(bd, "main.o"), "wb").write(b"\x4e\x71\x4e\x75")
        open(os.path.join(bd, "other.o"), "wb").write(b"\x00\x01")
        units = load_units(od, bd, None)
        assert len(units) == 2, units
        rep = build_report(units)
        assert rep["version"] == REPORT_VERSION
        main = [u for u in rep["units"] if u["name"] == "main"][0]
        assert main["measures"]["matched_code_percent"] == 100.0, main
        # other.o non ha target -> skippata (come objdiff senza target)
        assert rep["measures"]["total_units"] == 1, rep["measures"]
        assert [u["name"] for u in rep["units"]] == ["main"]
        print("  [ok] report v2: main 100%, unit senza target skippata")
        # 3b. target presente ma base mancante -> 0%, ma conteggiata
        open(os.path.join(od, "todo.o"), "wb").write(b"\x4e\x71")
        rep3 = build_report([{"name": "todo", "target": os.path.join(od, "todo.o"),
                              "base": os.path.join(bd, "todo.o"),
                              "source_path": None, "complete": False,
                              "progress_categories": []}])
        todo = [u for u in rep3["units"] if u["name"] == "todo"][0]
        assert todo["measures"]["matched_code_percent"] == 0.0, todo
        assert rep3["measures"]["total_units"] == 1
        print("  [ok] base mancante -> 0% conteggiata")
        # 4. units.json con complete
        uf = os.path.join(d, "units.json")
        json.dump({"units": [{"name": "main", "target": od + "/main.o",
                              "base": bd + "/main.o", "complete": True}]}, open(uf, "w"))
        rep2 = build_report(load_units(od, bd, uf))
        assert rep2["measures"]["complete_units"] == 1, rep2["measures"]
        print("  [ok] flag complete")
    print("ALL SELF-TESTS PASSED")


def main(argv=None):
    ap = argparse.ArgumentParser(description="M68k matching + report decomp.dev-compatibile")
    ap.add_argument("--target-dir", default="orig")
    ap.add_argument("--build-dir", default="build")
    ap.add_argument("--units", default="config/units.json")
    ap.add_argument("-o", "--output", default="build/report.json")
    ap.add_argument("--fail-under", type=float, default=None,
                    help="esce con errore se matched_code_percent < soglia")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)

    if a.self_test:
        self_test()
        return 0

    units = load_units(a.target_dir, a.build_dir, a.units)
    if not units:
        print(f"nessuna unit trovata (target={a.target_dir} build={a.build_dir})",
              file=sys.stderr)
        return 1
    report = build_report(units)
    os.makedirs(os.path.dirname(os.path.abspath(a.output)), exist_ok=True)
    with open(a.output, "w", encoding="utf-8") as f:
        json.dump(report, f, indent=2)
    m = report["measures"]
    print(f"units={len(report['units'])} code={m['matched_code']}/{m['total_code']} "
          f"({m['matched_code_percent']}%) func={m['matched_functions']}/{m['total_functions']} "
          f"-> {a.output}")
    for u in report["units"]:
        um = u["measures"]
        print(f"  {u['name']:20s} {um['matched_code_percent']:6.2f}% "
              f"({um['matched_code']}/{um['total_code']} bytes)")
    if a.fail_under is not None and m["matched_code_percent"] < a.fail_under:
        print(f"FAIL: {m['matched_code_percent']}% < {a.fail_under}%", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
