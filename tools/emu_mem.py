#!/usr/bin/env python3
"""Analizza un memory dump copylock (64B regs + RAM): estrae regioni,
entropia, refs DOS (JSR -xxx(A6)), stringhe. Uso: python tools/emu_mem.py mem.bin
"""
import math
import re
import struct
import sys
from collections import Counter


def entropy(b):
    c = Counter(b)
    n = len(b)
    return -sum(v / n * math.log2(v / n) for v in c.values())


def main(path):
    raw = open(path, "rb").read()
    regs = struct.unpack(">16I", raw[:64])
    mem = raw[64:]
    print("dump: %d byte, RAM %d byte (0x%x)" % (len(raw), len(mem), len(mem)))
    names = "D0 D1 D2 D3 D4 D5 D6 D7 A0 A1 A2 A3 A4 A5 A6 A7".split()
    for i, n in enumerate(names):
        print("  %s=%08x" % (n, regs[i]), end="  " if i % 4 != 3 else "\n")
    for base, size, tag in ((0x40000, 0x1000, "boot @40000"),
                            (0x8000, 0x1000, "rstar? @8000")):
        if base + size <= len(mem):
            seg = mem[base:base + size]
            print("%s entropy=%.2f head=%s" % (tag, entropy(seg), seg[:16].hex()))
    # JSR -xxx(A6) nella regione boot decrittata
    boot = mem[0x40000:0x41000] if len(mem) >= 0x41000 else b""
    print("--- JSR d16(A6) in boot+0..0x1000 ---")
    for m in re.finditer(b"\x4e\xae", boot):
        off = struct.unpack(">h", boot[m.start() + 2:m.start() + 4])[0]
        print("  boot+%04x: JSR %d(A6)  ; LVO %d" % (m.start(), off, off))
    print("--- stringhe in boot+0..0x1000 ---")
    for m in re.finditer(rb"[ -~]{5,}", boot):
        print("  boot+%04x: %s" % (m.start(), m.group().decode()))


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else "mem.bin")
