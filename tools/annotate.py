#!/usr/bin/env python3
"""annotate.py - report Markdown leggibile per le unit di decompilazione.

Per ogni unit: nome umano, desc, conf, dimensioni, % match, chiamanti/chiamati,
poi blocco ``` con il disassembly del target (capstone, max 60 righe).

Uso:
    python tools/annotate.py [--units config/units.json] [--names games/ramh/names.json]
                             [--report build/report.json] [--symbols game-ramh/symbols-rstar.json]
                             [--func-dir orig/func] [--base 0x8000] [-o build/annotated.md]
                             [--self-test]
"""
import argparse
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import callgraph  # noqa: E402

MAX_DISASM = 60


def addr_of(name):
    m = re.search(r"_([0-9A-Fa-f]+)$", name)
    return int(m.group(1), 16) if m else None


def load_json(p, default):
    try:
        return json.load(open(p, encoding="utf-8"))
    except Exception:
        return default


def main(argv=None):
    ap = argparse.ArgumentParser(description="Report Markdown annotato per unit M68k")
    ap.add_argument("--units", default="config/units.json")
    ap.add_argument("--names", default="games/ramh/names.json")
    ap.add_argument("--report", default="build/report.json")
    ap.add_argument("--symbols", default="game-ramh/symbols-rstar.json")
    ap.add_argument("--func-dir", default="orig/func")
    ap.add_argument("--base", default="0x8000")
    ap.add_argument("-o", "--output", default="build/annotated.md")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()

    base = int(a.base, 16)
    units = load_json(a.units, {"units": []})["units"]
    names = load_json(a.names, {})
    report = load_json(a.report, {})
    rmap = {u["name"]: u for u in report.get("units", [])}
    funcs, edges = callgraph.build(a.symbols, a.func_dir, base)
    callees = {f["name"]: set(edges.get(f["name"], [])) for f in funcs}
    callers = {}
    for f, cs in callees.items():
        for c in cs:
            callers.setdefault(c, set()).add(f)

    lines = ["# Annotated decomp report", ""]
    lines.append("| id | nome | size | match% | chiamanti | chiamati |")
    lines.append("|---|---|---|---|---|---|")
    for u in units:
        n = u["name"]
        nm = names.get(n, {})
        human = nm.get("name", n) if isinstance(nm, dict) else n
        sz = os.path.getsize(u["target"]) if os.path.isfile(u["target"]) else 0
        pct = rmap.get(n, {}).get("measures", {}).get("matched_code_percent", "?")
        lines.append("| %s | %s | %d | %s | %d | %d |" % (
            n, human, sz, pct, len(callers.get(n, ())), len(callees.get(n, ()))))

    for u in units:
        n = u["name"]
        nm = names.get(n, {})
        human = nm.get("name", n) if isinstance(nm, dict) else n
        desc = nm.get("desc", "") if isinstance(nm, dict) else ""
        conf = nm.get("conf", "?") if isinstance(nm, dict) else "?"
        pct = rmap.get(n, {}).get("measures", {}).get("matched_code_percent", "?")
        lines += ["", "## %s" % n, "",
                  "- nome: `%s`" % human,
                  "- desc: %s" % (desc or "-"),
                  "- conf: %s" % conf,
                  "- match: %s%%" % pct,
                  "- chiamanti: %s" % (", ".join(sorted(callers.get(n, ()))) or "-"),
                  "- chiamati: %s" % (", ".join(sorted(callees.get(n, ()))) or "-"),
                  "", "```"]
        p = u["target"]
        if os.path.isfile(p):
            d = open(p, "rb").read()
            try:
                from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
                md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
                ins = list(md.disasm(d, 0))
                for i in ins[:MAX_DISASM]:
                    lines.append("%02x %-10s %s" % (i.address, i.mnemonic, i.op_str))
                if len(ins) > MAX_DISASM:
                    lines.append("... (%d righe omesse)" % (len(ins) - MAX_DISASM))
            except Exception as e:
                lines.append("disasm non disponibile: %s" % e)
        else:
            lines.append("(target mancante: %s)" % p)
        lines.append("```")

    os.makedirs(os.path.dirname(os.path.abspath(a.output)), exist_ok=True)
    with open(a.output, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")
    print("scritto %s (%d unit)" % (a.output, len(units)))
    return 0


def self_test():
    print("== annotate.py self-test ==")
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        for n, blob in (("f1", bytes.fromhex("4e75")), ("f2", bytes.fromhex("60024e75"))):
            open(os.path.join(d, n + ".bin"), "wb").write(blob)
        up = os.path.join(d, "units.json")
        json.dump({"units": [
            {"name": "f1", "target": os.path.join(d, "f1.bin"), "base": os.path.join(d, "b1.o")},
            {"name": "f2", "target": os.path.join(d, "f2.bin"), "base": os.path.join(d, "b2.o")},
        ]}, open(up, "w"))
        np_ = os.path.join(d, "names.json")
        json.dump({"f1": {"name": "ritorna", "desc": "rts", "conf": "high"},
                   "f2": {"name": "salta", "desc": "bra+rts", "conf": "med"}},
                  open(np_, "w"))
        rp = os.path.join(d, "report.json")
        json.dump({"units": [
            {"name": "f1", "measures": {"matched_code_percent": 100.0}},
            {"name": "f2", "measures": {"matched_code_percent": 50.0}},
        ]}, open(rp, "w"))
        sp = os.path.join(d, "symbols.json")
        json.dump({"functions": [
            {"name": "f1", "address": "0x8000", "size": 2},
            {"name": "f2", "address": "0x8002", "size": 4},
        ]}, open(sp, "w"))
        out = os.path.join(d, "out.md")
        rc = main(["--units", up, "--names", np_, "--report", rp,
                   "--symbols", sp, "--func-dir", d, "--base", "0x8000",
                   "-o", out])
        assert rc == 0
        txt = open(out, encoding="utf-8").read()
        assert "## f1" in txt and "## f2" in txt
        assert "ritorna" in txt and "salta" in txt
        assert "100.0" in txt and "50.0" in txt
        assert "```" in txt and "rts" in txt
        print("  [ok] tabella + sezioni + disasm presenti")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
