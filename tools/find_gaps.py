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
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import m68k_flow  # noqa: E402

MIN_GAP = 16
MIN_INSNS = 4


def slice_fileoff(fn, base):
    """Offset file di inizio slice, dall'indirizzo Ghidra nel nome file
    (FUN_0000859a, GAP_008000, CALL_0083DC). Ritorna None se non parsabile."""
    import re
    m = re.search(r"_([0-9A-Fa-f]{4,6})(?:_|\.)", fn)
    if m:
        return int(m.group(1), 16) - base
    return None


def find_from_targets(data, funcs, base, func_dir, extra_spans=()):
    """Per ogni target di call che non cade in funzioni note, prova decode.

    Ritorna [{name, address, size}] con nomi CALL_XXXXXX. Copre codice che
    i gap-scan mancano (entry non a inizio gap).

    ATTENZIONE coordinate: il decode della slice e' relativo a 0, quindi
    i target rel vanno spostati dell'offset file della slice (dal nome file);
    jsr/jmp assoluti sono gia' indirizzi -> basta sottrarre la base.
    """
    import os
    import struct
    known = []
    for a, s in funcs:
        known.append((a - base, a - base + s))
    known += [(s, e) for s, e in extra_spans]
    known.sort()
    # 1) raccogli tutti gli entry candidati (offset file)
    cands = set()
    for fn in sorted(os.listdir(func_dir)):
        if not fn.endswith(".bin"):
            continue
        s_off = slice_fileoff(fn, base)
        if s_off is None:
            continue
        blob = open(os.path.join(func_dir, fn), "rb").read()
        vis = m68k_flow.disasm_recursive(blob, 0, [0])
        for addr, (size, text) in vis.items():
            m = text.split(None, 1)[0].split(".")[0]
            if m not in ("bsr", "jsr", "bra", "jmp"):
                continue
            raw = blob[addr:addr + size]
            t = None
            if m in ("bsr", "bra"):
                disp = struct.unpack(">b", raw[1:2])[0] if size == 2 \
                    else struct.unpack(">h", raw[2:4])[0]
                t = s_off + addr + 2 + disp
            elif m == "jsr":
                if len(raw) >= 6 and raw[0] == 0x4E and raw[1] == 0xB9:
                    t = struct.unpack(">I", raw[2:6])[0] - base
                elif len(raw) >= 4 and raw[0] == 0x4E and raw[1] == 0xBA:
                    t = s_off + addr + 2 + struct.unpack(">h", raw[2:4])[0]
                else:
                    continue
            elif m == "jmp" and len(raw) >= 6 and raw[0] == 0x4E and raw[1] == 0xF9:
                t = struct.unpack(">I", raw[2:6])[0] - base
            else:
                continue
            if t is not None and 0 <= t < len(data):
                cands.add(t)
    # 2) in ordine di indirizzo: la entry piu' bassa vince, le altre
    #    sovrapposte vengono assorbite (niente doppi conteggi)
    claimed = [list(x) for x in known]
    found = []

    def covered2(t):
        return any(s <= t < e for s, e in claimed)

    def next_start2(t):
        nx = [s for s, e in claimed if s > t]
        return min(nx) if nx else len(data)

    for t in sorted(cands):
        if covered2(t):
            continue
        size = try_entry(data, base, base + t)
        if not size:
            continue
        size = min(size, next_start2(t) - t)
        if size < MIN_GAP:
            continue
        found.append({"name": "CALL_%06X" % (base + t),
                      "address": "0x%x" % (base + t), "size": size})
        claimed.append([t, t + size])
        claimed.sort()
    return found


def try_entry(data, base, entry, chunk=0x400):
    """Prova decode ricorsivo da entry: ritorna size se run coerente con RTS."""
    off = entry - base
    if off < 0 or off >= len(data):
        return 0
    vis = m68k_flow.disasm_recursive(data[off:off + chunk], entry, [entry])
    if len(vis) < MIN_INSNS:
        return 0
    addrs = sorted(vis)
    end = addrs[0]
    for a in addrs[1:]:
        prev = max(x for x in addrs if x < a)
        if a - prev > 8:
            break
        end = a
    size = end - addrs[0] + vis[end][0]
    last_mn = vis[end][1].split()[0].split(".")[0]
    if last_mn not in ("rts", "rte", "jmp", "bra", "rtr"):
        return 0
    seg = data[off:off + size]
    if size < MIN_GAP or sum(1 for b in seg if b == 0) > len(seg) // 3:
        return 0
    return size


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
        if sum(1 for b in seg if b == 0) > len(seg) // 3:
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
    ap.add_argument("--func-dir", default="orig/func")
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
    if os.path.isdir(a.func_dir):
        gap_spans = [((int(f["address"], 16) - base),
                      (int(f["address"], 16) - base + f["size"])) for f in found]
        extra = find_from_targets(data, funcs, base, a.func_dir,
                                  extra_spans=gap_spans)
        have = set(f["address"] for f in found)
        found += [f for f in extra if f["address"] not in have]
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
    # target di call in mezzo a dati -> CALL_xxxxxx
    # (la slice ha l'indirizzo nel nome, come FUN_/GAP_/CALL_)
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        # caller: bsr.w a 0x1C; 22 zeri; callee 8 nop+rts a 0x1C
        caller = bytes.fromhex("6100001a") + bytes.fromhex("4e75")
        open(os.path.join(d, "T_008000.bin"), "wb").write(caller)
        data2 = caller + b"\x00" * 22 + bytes.fromhex("4e71") * 8 + bytes.fromhex("4e75")
        found3 = find_from_targets(data2, [(0x8000, 6)], 0x8000, d)
        assert len(found3) == 1 and found3[0]["address"] == "0x801c", found3
        print("  [ok] call-target in dati -> CALL_00801C")
    # regressione: target rel va spostato dell'offset file della slice.
    # Qui t_rel=0x100 e' coperto come offset file, ma il vero target
    # (file 0x200) non lo e': la vecchia versione lo saltava.
    with tempfile.TemporaryDirectory() as d:
        caller2 = bytes.fromhex("610000fe") + bytes.fromhex("4e75") + b"\x00" * 10
        assert len(caller2) == 16
        open(os.path.join(d, "T_008100.bin"), "wb").write(caller2)
        data3 = bytearray(0x200 + 18)
        data3[0:2] = bytes.fromhex("4e75")
        data3[0x100:0x100 + 16] = caller2
        data3[0x200:0x200 + 18] = bytes.fromhex("4e71") * 8 + bytes.fromhex("4e75")
        found4 = find_from_targets(bytes(data3), [(0x8000, 6), (0x8100, 0x10)],
                                   0x8000, d)
        assert len(found4) == 1 and found4[0]["address"] == "0x8200", found4
        print("  [ok] target rel spostato su offset file slice")
    # slice senza indirizzo nel nome: saltata, non crash
    with tempfile.TemporaryDirectory() as d:
        open(os.path.join(d, "c.bin"), "wb").write(bytes.fromhex("6100001a4e75"))
        found5 = find_from_targets(bytes.fromhex("6100001a4e75"), [(0x8000, 6)],
                                   0x8000, d)
        assert found5 == [], found5
        print("  [ok] slice senza indirizzo saltata")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
