#!/usr/bin/env python3
"""Analizza il trace copylock (UTF-16): coverage eseguita, chi legge $26."""
import re
import sys

path = sys.argv[1] if len(sys.argv) > 1 else (
    ".toolchain/disk/boot_trace.log")
raw = open(path, "rb").read().decode("utf-16-le", errors="replace")
lines = raw.splitlines()
lst = [l for l in lines if re.match(r"^[0-9a-f]{8} ", l)]
exe = [l for l in lst if len(l) > 9 and l[8] == " " and l[9] == " "]
nex = [l for l in lst if l not in exe]
print("eseguite:", len(exe), "| non eseguite:", len(nex))
adds = sorted(set(l.split()[0] for l in exe))
print("range eseguiti:", adds[0], "..", adds[-1], "addrs:", len(adds))
print("--- eseguite che citano 0026 ---")
for l in exe:
    code = l[10:34]
    if "0026" in code:
        print(l)
print("--- eseguite con (a0) ---")
for l in exe:
    if "(a0)" in l:
        print(l)
