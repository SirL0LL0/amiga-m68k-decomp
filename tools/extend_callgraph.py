#!/usr/bin/env python3
"""extend_callgraph.py - aggiunge archi JSR assoluti al call graph.

Cerca in ogni slice le istruzioni JSR assolute (4EB9 xxxxxx / 4EBA xxxxxx)
e mappa il target alla funzione nota che lo contiene (offset file =
indirizzo Ghidra - base). I target che non cadono in nessuna funzione nota
vengono segnalati ma non aggiunti.

Uso:
    python tools/extend_callgraph.py [--symbols symbols.json] [--func-dir orig/func]
                                     [--base 0x8000] [-o build/callgraph.json]
                                     [--self-test]
"""
import argparse
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))


def find_jsrs(data):
    """Ritorna [target_fileoff] delle JSR assolute (4EB9/4EBA)."""
    out = []
    i = 0
    n = len(data)
    while i + 6 <= n:
        w = (data[i] << 8) | data[i + 1]
        if w == 0x4EB9:  # JSR abs.l
            t = struct.unpack_from(">I", data, i + 2)[0]
            out.append(t & 0xFFFFFF)
            i += 6
        elif w == 0x4EBA:  # JSR abs.w
            t = struct.unpack_from(">H", data, i + 2)[0]
            out.append(t & 0xFFFF)
            i += 4
        else:
            i += 2
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
    funcs.sort(key=lambda g: g["start"])

    def containing(t):
        best = None
        for g in funcs:
            if g["start"] <= t < g["end"]:
                if best is None or g["start"] > best["start"]:
                    best = g
        return best["name"] if best else None

    edges = {}
    unmapped = set()
    for fn in sorted(os.listdir(func_dir)):
        if not fn.endswith(".bin"):
            continue
        uname = fn[:-4]
        blob = open(os.path.join(func_dir, fn), "rb").read()
        calls = set()
        for t in find_jsrs(blob):
            who = containing(t)
            if who and who != uname:
                calls.add(who)
            elif who is None:
                unmapped.add(t)
        if calls:
            edges[uname] = sorted(calls)
    return funcs, edges, sorted(unmapped)


def main(argv=None):
    ap = argparse.ArgumentParser(description="Estendi call graph con JSR assoluti")
    ap.add_argument("--symbols", default="game-ramh/symbols-rstar.json")
    ap.add_argument("--func-dir", default="orig/func")
    ap.add_argument("--base", default="0x8000")
    ap.add_argument("-o", "--output", default="build/callgraph.json")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()

    base = int(a.base, 16)
    funcs, edges, unmapped = build(a.symbols, a.func_dir, base)
    os.makedirs(os.path.dirname(os.path.abspath(a.output)), exist_ok=True)
    json.dump({"functions": [g["name"] for g in funcs], "edges": edges},
              open(a.output, "w", encoding="utf-8"), indent=1)
    print("JSR mappate: %d archi; target fuori funzioni note: %s"
          % (sum(len(v) for v in edges.values()),
             [hex(t) for t in unmapped] or "nessuno"))
    return 0


def self_test():
    print("== extend_callgraph.py self-test ==")
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        # f1 chiama f2 (JSR assoluto a f2+4, dentro f2)
        f1 = bytes.fromhex("4eb900000008") + bytes.fromhex("4e75")  # JSR 0x0008; RTS
        f2 = bytes.fromhex("4e71") * 4 + bytes.fromhex("4e75")     # NOP*4; RTS (0x0008 = f2+8? no)
        # f2 inizia a 0x0008: JSR 0x0008 punta all'inizio di f2
        f1 = bytes.fromhex("4eb900000008") + bytes.fromhex("4e75")
        open(os.path.join(d, "f1.bin"), "wb").write(f1)
        open(os.path.join(d, "f2.bin"), "wb").write(f2)
        sp = os.path.join(d, "s.json")
        json.dump({"functions": [
            {"name": "f1", "address": "0x8000", "size": 6},
            {"name": "f2", "address": "0x8008", "size": 10}]}, open(sp, "w"))
        funcs, edges, unmapped = build(sp, d, 0x8000)
        assert edges.get("f1") == ["f2"], edges
        assert unmapped == [], unmapped
        print("  [ok] JSR assoluto mappato alla funzione contenitrice")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
