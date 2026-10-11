#!/usr/bin/env python3
"""callgraph.py - grafo delle chiamate statico da slice M68k + simboli Ghidra.

Trova BSR/JSR con target calcolabile (base PC+2 del 68000) e li mappa sulle
funzioni (range Ghidra). Uso:
    python tools/callgraph.py --symbols game-ramh/symbols-rstar.json --func-dir orig/func
    python tools/callgraph.py --callers FUN_00013554
    python tools/callgraph.py --self-test
"""

import argparse
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))


def calls_in(code):
    """Ritorna [target_fileoff] delle call PC-rel/assolute nello slice."""
    import m68k_flow
    import struct

    def s32(v):
        return v - 0x100000000 if v >= 0x80000000 else v

    out = []
    for addr, (size, text) in m68k_flow.disasm_recursive(code, 0, [0]).items():
        parts = text.split(None, 1)
        if len(parts) < 2:
            continue
        m, op = parts[0].split(".")[0], parts[1]
        raw = code[addr:addr + size]
        if m == "bsr":
            disp = struct.unpack(">b", raw[1:2])[0] if size == 2 \
                else struct.unpack(">h", raw[2:4])[0]
            out.append(addr + 2 + disp)
        elif m == "jsr":
            if len(raw) >= 4 and raw[0] == 0x4E and raw[1] == 0xBA:  # JSR d16(PC)
                out.append(addr + 2 + struct.unpack(">h", raw[2:4])[0])
            elif len(raw) >= 6 and raw[0] == 0x4E and raw[1] == 0xB9:  # JSR abs.l
                out.append(struct.unpack(">I", raw[2:6])[0])
    return out


def build(symbols_path, func_dir, base):
    syms = json.load(open(symbols_path, encoding="utf-8"))["functions"]
    funcs = []
    for f in syms:
        if f.get("external") or f.get("thunk"):
            continue
        addr = int(f["address"], 16)
        funcs.append({"name": f["name"], "start": addr - base,
                      "end": addr - base + int(f.get("size", 0))})
    funcs.sort(key=lambda f: f["start"])
    edges = {}
    for f in funcs:
        p = os.path.join(func_dir, f["name"] + ".bin")
        if not os.path.isfile(p):
            continue
        data = open(p, "rb").read()
        # il file puo' essere piu' corto del range Ghidra: usa offset relativi
        calls = set()
        tgts = [f["start"] + t for t in calls_in(data)]
        starts = {g["name"]: g["start"] for g in funcs}
        for t in tgts:
            exact = [n for n, s in starts.items() if s == t and n != f["name"]]
            if exact:
                calls.update(exact)
                continue
            for g in funcs:
                if g["start"] < t < g["end"] and g["name"] != f["name"]:
                    calls.add(g["name"])
        edges[f["name"]] = sorted(calls)
    return funcs, edges


def main(argv=None):
    ap = argparse.ArgumentParser(description="Call graph statico M68k")
    ap.add_argument("--symbols", default="game-ramh/symbols-rstar.json")
    ap.add_argument("--func-dir", default="orig/func")
    ap.add_argument("--base", default="0x8000")
    ap.add_argument("--callers", default=None)
    ap.add_argument("--callees", default=None)
    ap.add_argument("--json", default=None)
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    funcs, edges = build(a.symbols, a.func_dir, int(a.base, 16))
    if a.json:
        json.dump({"functions": [f["name"] for f in funcs], "edges": edges},
                  open(a.json, "w"), indent=1)
        print("scritto", a.json)
        return 0
    if a.callers:
        print("chiamanti di", a.callers, ":")
        for f, cs in sorted(edges.items()):
            if a.callers in cs:
                print("  ", f)
        return 0
    if a.callees:
        print("chiamate da", a.callees, ":")
        for c in edges.get(a.callees, []):
            print("  ", c)
        return 0
    # riassunto: radici (mai chiamate) e grado
    called = set(c for cs in edges.values() for c in cs)
    print("funzioni: %d, archi: %d" % (len(funcs), sum(len(c) for c in edges.values())))
    print("--- radici (mai chiamate, entry candidate) ---")
    for f in funcs:
        if f["name"] not in called and edges.get(f["name"]):
            print("  %-18s chiama %d" % (f["name"], len(edges[f["name"]])))
    print("--- top chiamate (out-degree) ---")
    for f in sorted(funcs, key=lambda f: -len(edges.get(f["name"], [])))[:12]:
        print("  %-18s -> %s" % (f["name"], ", ".join(edges[f["name"]][:6])))


def self_test():
    print("== callgraph.py self-test ==")
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        # f calls g (bsr.w +4 -> g), g chiama h assoluta fuori range (ignorata)
        f = bytes.fromhex("61000004") + bytes.fromhex("4e75")
        g = bytes.fromhex("4e754e75")
        open(os.path.join(d, "f.bin"), "wb").write(f)
        open(os.path.join(d, "g.bin"), "wb").write(g)
        sp = os.path.join(d, "s.json")
        json.dump({"functions": [
            {"name": "f", "address": "0x8000", "size": 6},
            {"name": "g", "address": "0x8006", "size": 4}]}, open(sp, "w"))
        funcs, edges = build(sp, d, 0x8000)
        assert edges == {"f": ["g"], "g": []}, edges
        print("  [ok] arco f->g, base PC+2")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
