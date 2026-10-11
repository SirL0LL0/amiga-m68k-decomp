#!/usr/bin/env python3
"""Fake C compiler, SOLO PER TEST dell'agent loop (mai con vbcc veri).

Legge il candidato .c, cerca una riga '/* FAKE-EMIT: <hex> */' ed emette
quei byte su {out}. Senza marker emette 1 byte zero.
Uso: python tools/agent/fake_cc.py <src.c> <out.o>
"""
import re
import sys


def main():
    src, out = sys.argv[1], sys.argv[2]
    text = open(src, encoding="utf-8").read()
    m = re.search(r"/\* FAKE-EMIT: ([0-9a-fA-F]+) \*/", text)
    data = bytes.fromhex(m.group(1)) if m else b"\x00"
    open(out, "wb").write(data)
    print("fake-cc: %d bytes <- %s" % (len(data), src))


if __name__ == "__main__":
    main()
