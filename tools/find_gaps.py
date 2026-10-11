#!/usr/bin/env python3
"""find_gaps.py - trova codice eseguibile nei gap tra funzioni Ghidra.

Ghidra non trova tutte le funzioni (code/data interleaved). Per ogni gap tra
funzioni consecutive prova decode ricorsivo da inizio gap: se produce un run
coerente che termina (rts/rte/jmp/bra fuori), e' una funzione persa.

Uso:
    python tools/find_gaps.py --symbols game-ramh/symbols-rstar.json --exe game-ramh/RSTAR --base 0x8000 -o game-ramh/gaps.json
    python tools/symbols_to_units.py --symbols ... --extra-symbols game-ramh/gaps.json ...
    python tools/find_gaps.py --self-test
"""

import argparse
import json
import sys

HERE = __import__("os").path.dirname(__import__("os").path.abspath(__file__))
sys.path.insert(0, HERE)
import m68k_flow  # noqa: E402

MIN_GAP = 16
MIN_INSNS = 4


def find(data, funcs, base):
    """funcs = [(addr_ghidra, size)], data = file intero, base = load base.

    Ritorna [{name, address(hex ghidra), size}]."""
    order = sorted(funcs)
    spans = [(a - base, a - base + s) for a, s in order]
    gaps = []
    for (s0, e0), (s1, e1) in zip(spans, spans[1:]):
        if s1 - e0 >= MIN_GAP:
            gaps.append((e0, s1))
    # coda dopo ultima funzione? no: dati/testi, solo gap interni + testa
    if spans and spans[0][0] >= MIN_GAP:
        gaps.insert(0, (0, spans[0][0]))
    found = []
    for gs, ge in gaps:
        vis = m68k_flow.disasm_recursive(data[gs:ge], base + gs, [base + gs])
        if len(vis) < MIN_INSNS:
            continue
        addrs = sorted(vis)
        # contiguo dall'inizio?
        end = addrs[0]
        for a in addrs[1:]:
            prev = max(x for x in addrs if x < a)
            if a - prev > 8:
                break
            end = a
        size = end - addrs[0] + vis[end][0]
        # deve terminare con rts/rte/jmp/bra (non troncato a meta')
        last_mn = vis[end][1].split()[0].split(".")[0]
        if last_mn not in ("rts", "rte", "jmp", "bra", "rtr"):
            continue
        if size < MIN_GAP:
            continue
        seg = data[addrs[0] - base:addrs[0] - base + size]
        if sum(1 for b in seg if b == 0) > len(seg) // 4:
            continue  # padding/zeri, non codice (es. ori.b #0,d0 finti)
        found.append({"name": "GAP_%06X" % addrs[0],
                      "address": "0x%x" % addrs[0], "size": size,
                      "gap": [gs, ge]})
    return found


def main(argv=None):
    ap = argparse.ArgumentParser(description="Trova funzioni nei gap Ghidra")
    ap.add_argument("--symbols", default="game-ramh/symbols-rstar.json")
    ap.add_argument("--exe", default="game-ramh/RSTAR")
    ap.add_argument("--base", default="0x8000")
    ap.add_argument("-o", "--output", default="game-ramh/gaps.json")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    base = int(a.base, 16)
    syms = json.load(open(a.symbols, encoding="utf-8"))["functions"]
    funcs = [(int(f["address"], 16), int(f.get("size", 0)))
             for f in syms if not f.get("external") and not f.get("thunk")]
    data = open(a.exe, "rb").read()
    found = find(data, funcs, base)
    json.dump({"functions": found}, open(a.output, "w"), indent=1)
    total = sum(f["size"] for f in found)
    print("gap-funzioni: %d (%d byte) -> %s" % (len(found), total, a.output))
    for f in found[:30]:
        print("  %-14s @%s size=%d" % (f["name"], f["address"], f["size"]))
    if len(found) > 30:
        print("  ... +%d" % (len(found) - 30))
    return 0


def self_test():
    print("== find_gaps.py self-test ==")
    # due funzioni con gap di 8 NOP + RTS in mezzo (18B >= MIN_GAP)
    gap_code = bytes.fromhex("4e71") * 8 + bytes.fromhex("4e75")
    data = bytes.fromhex("4e75") + gap_code + bytes.fromhex("4e75")
    funcs = [(0x8000, 2), (0x8000 + 2 + len(gap_code), 2)]
    found = find(data, funcs, 0x8000)
    assert len(found) == 1 and found[0]["size"] == len(gap_code), found
    print("  [ok] gap NOP+RTS trovato")
    # gap dati (zeri) ignorato
    found2 = find(bytes.fromhex("4e75") + b"\x00" * 20 + bytes.fromhex("4e75"),
                  [(0x8000, 2), (0x8024, 2)], 0x8000)
    assert found2 == [], found2
    print("  [ok] gap dati ignorato")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
