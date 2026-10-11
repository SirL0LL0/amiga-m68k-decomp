#!/usr/bin/env python3
"""m68k_flow.py - disassembly ricorsivo M68k (segue i salti, salta i dati).

Uso:
    python tools/m68k_flow.py file.bin --org 0x0 --entry 0x0 [--entry 0x..]
    python tools/m68k_flow.py --self-test
"""

import argparse
import sys

COND = {"bra", "bsr", "bhi", "bls", "bcc", "bcs", "bne", "beq", "bvc",
        "bvs", "bpl", "bmi", "bge", "blt", "bgt", "ble"}


def disasm_recursive(data, org, entries):
    from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
    md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
    md.detail = True
    visited = {}  # addr -> (size, text)
    work = list(entries)
    while work:
        pc = work.pop()
        while True:
            if pc in visited or pc < 0 or pc - org >= len(data):
                break
            try:
                ins = next(md.disasm(data[pc - org:pc - org + 16], org + (pc - org)))
            except StopIteration:
                break
            if ins.address != pc:
                break
            m = ins.mnemonic.split(".")[0]  # capstone aggiunge .b/.w/.l
            visited[pc] = (ins.size, "%-10s %s" % (ins.mnemonic, ins.op_str))
            nxt = pc + ins.size
            if m in COND or m in ("bsr", "bra", "jmp"):
                # target assoluto reso da capstone come $addr (anche per i branch:
                # $addr e' gia' l'indirizzo di salto, non il displacement;
                # gli operandi branch M68K hanno tipo dedicato, non IMM)
                s = ins.op_str.strip()
                if s.startswith("$"):
                    try:
                        work.append(int(s[1:].split(",")[0].split("(")[0].split()[0], 16))
                    except ValueError:
                        pass
            if m in ("rts", "rte", "rtr", "jmp", "bra") and m != "bsr":
                break
            if m in ("jsr",):
                pass  # call: continua dopo, non segue (sottofunzione ignota)
            pc = nxt
    return visited


def main(argv=None):
    ap = argparse.ArgumentParser(description="Disassembly ricorsivo M68k")
    ap.add_argument("binfile", nargs="?")
    ap.add_argument("--org", default="0x0")
    ap.add_argument("--entry", action="append", default=[])
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    data = open(a.binfile, "rb").read()
    org = int(a.org, 16)
    entries = [int(e, 16) for e in a.entry] or [org]
    vis = disasm_recursive(data, org, entries)
    for addr in sorted(vis):
        size, text = vis[addr]
        print("%06x  %s" % (addr, text))
    print("# %d istruzioni da %d entry" % (len(vis), len(entries)))
    return 0


def self_test():
    print("== m68k_flow.py self-test ==")
    # bra.s +4; nop; nop; rts  -> segue il salto a 6, salta i nop a 2 e 4
    code = bytes.fromhex("60044e714e714e75")
    vis = disasm_recursive(code, 0, [0])
    addrs = sorted(vis)
    assert addrs[0] == 0 and "bra" in vis[0][1], vis
    assert 6 in vis and "rts" in vis[6][1], vis
    assert 2 not in vis and 4 not in vis, vis
    print("  [ok] segue bra, salta codice morto")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
