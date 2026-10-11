#!/usr/bin/env python3
"""Confronta funzioni loro (decomp/) vs mie unit: overlap indirizzi e archi call."""
import json
import re
import sys

BASE = 0x8000
LORO = "C:/Users/lollo/Downloads/RAMH traduzione/decomp/"


def addr_of(name):
    m = re.search(r"_([0-9A-Fa-f]+)$", name)
    return int(m.group(1), 16) if m else None


def main():
    lorof = json.load(open(LORO + "funzioni.json", encoding="utf-8"))
    mie = json.load(open("config/units.json"))["units"]
    my_addrs = set(a for a in (addr_of(u["name"]) for u in mie) if a is not None)
    for shift in (0x0, 0x100, -0x100, 0x2, -0x2):
        lo = set(int(k, 16) - shift for k in lorof)
        print("shift %s: in comune %d / 228" % (hex(shift), len(my_addrs & lo)))
    lo_addrs = set(int(k, 16) for k in lorof)
    print("mie addr: %d loro addr: %d" % (len(my_addrs), len(lo_addrs)))
    print("in comune: %d" % len(my_addrs & lo_addrs))
    sl = sorted(lo_addrs - my_addrs)
    sm = sorted(my_addrs - lo_addrs)
    print("solo loro: %d %s" % (len(sl), [hex(x) for x in sl[:15]]))
    print("solo mie: %d %s" % (len(sm), [hex(x) for x in sm[:15]]))
    # accordo archi: loro chiama (decimali) vs miei
    called = {}
    for u in mie:
        a = addr_of(u["name"])
        if a is not None:
            called[a] = u["name"]
    agree = disagree = 0
    ex = []
    for k, f in lorof.items():
        a = int(k, 16)
        if a not in my_addrs:
            continue
        for c in f.get("chiama", []):
            # c decimale = indirizzo ghidra?
            if c in my_addrs:
                agree += 1
            else:
                disagree += 1
                if len(ex) < 8:
                    ex.append((k, hex(c)))
    print("archi loro verso addr miei: ok=%d fuori=%d es: %s" % (agree, disagree, ex))
    validate_counts(lorof, mie)
    return 0


def validate_counts(lorof, mie):
    """Per le coppie mappate (mia addr = loro key - 0x100): confronta
    conteggio istruzioni (mio disasm vs loro 'istruzioni')."""
    from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
    import os
    md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
    md.skipdata = True
    match = rough = bad = 0
    badex = []
    for u in mie:
        a = addr_of(u["name"])
        if a is None:
            continue
        k = "%05x" % (a + 0x100)
        if k not in lorof:
            continue
        p = u["target"]
        if not os.path.isfile(p):
            continue
        d = open(p, "rb").read()
        n = sum(1 for _ in md.disasm(d, 0))
        li = lorof[k]["istruzioni"] or 0
        r = n / li if li else 9
        if 0.8 <= r <= 1.25:
            match += 1
        elif 0.4 <= r <= 2.5:
            rough += 1
        else:
            bad += 1
            if len(badex) < 10:
                badex.append((u["name"], k, n, li))
    print("istruzioni match=%d rough=%d bad=%d" % (match, rough, bad))
    for b in badex:
        print("  bad:", b)


if __name__ == "__main__":
    sys.exit(main())
