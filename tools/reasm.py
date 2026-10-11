#!/usr/bin/env python3
"""reasm.py - riassembla slice di funzione in sorgente vasm byte-identico.

Per ogni unit senza asm/*.s ne' src/*.c: decode lineare (capstone) con label
per i target in-slice, dc.w letterali per riferimenti fuori slice e dati,
assemble con vasmm68k, diff col target; le istruzioni divergenti vengono
sostituite con dc.w (stessa lunghezza) finche' non e' 100%.
Convergenza garantita: nel caso peggiore tutto diventa dc.w.

Uso:
    python tools/reasm.py --func FUN_0000b85a
    python tools/reasm.py --all                # solo unit senza sorgenti
    python tools/reasm.py --self-test
"""

import argparse
import json
import os
import re
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import diff_m68k  # noqa: E402

COND = {"bra", "bsr", "bhi", "bls", "bcc", "bcs", "bne", "beq", "bvc",
        "bvs", "bpl", "bmi", "bge", "blt", "bgt", "ble"}

VASM_CANDIDATES = [
    os.path.join(HERE, "..", ".toolchain", "vbcc-win", "vbcc", "bin",
                 "vasmm68k_mot.exe"),
    "vasmm68k_mot",
    "vasmm68k_mot.exe",
]


def find_vasm():
    for c in VASM_CANDIDATES:
        if os.path.isfile(c):
            return c
    for c in VASM_CANDIDATES:
        try:
            subprocess.run([c], capture_output=True, timeout=10)
            return c
        except Exception:
            pass
    return None


def decode(data):
    """Ritorna [(addr, size, mnemonic, op_str)] con skipdata per i dati."""
    from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
    md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
    md.skipdata = True
    out = []
    for ins in md.disasm(data, 0):
        out.append((ins.address, ins.size, ins.mnemonic, ins.op_str))
    return out


def abs_targets(data):
    """Target assoluti ($addr) citati nelle istruzioni -> {addr}."""
    outs = set()
    for _, _, _, op in decode(data):
        for m in re.finditer(r"\$([0-9a-fA-F]+)(?![0-9a-zA-Z])", op):
            try:
                outs.add(int(m.group(1), 16))
            except ValueError:
                pass
    return outs


def norm_op(op):
    """Rende gli operandi capstone compatibili vasm-mot: niente spazi dopo
    le virgole ($dff09c, non $dff09c con spazio)."""
    return re.sub(r",\s+", ",", op.strip())


def fix_abs_operand(op):
    """Aggiunge .l agli assoluti >$7FFF senza suffisso; .l a btst Dn."""
    def rep(m):
        val = int(m.group(1), 16)
        if val > 0x7FFF:
            return "$" + m.group(1) + ".l"
        return m.group(0)
    op = re.sub(r"\$([0-9a-fA-F]{1,8})(?![0-9a-zA-Z.l])", rep, op)
    return op


def render(data, name, ghidra_addr=None):
    """Genera righe sorgente vasm. Ritorna (righe, marks).

    marks = [(addr, size, indice_riga_principale)] per mappare ogni
    istruzione decodificata alla sua riga (serve al fallback dc.w).
    I branch/lea-pc usano sempre label (il fallback corregge i target).
    """
    insns = decode(data)
    n = len(data)
    targets = set()
    for addr, size, mn, op in insns:
        m = mn.split(".")[0]
        if m in COND or m in ("jmp", "bsr", "lea"):
            s = op.strip()
            if s.startswith("$"):
                try:
                    t = int(s[1:].split(",")[0].split("(")[0].split()[0], 16)
                    if 0 <= t < n:
                        targets.add(t)
                except ValueError:
                    pass
    result = ["\t\topt\to-", "", "%s:" % name]
    marks = []
    for addr, size, mn, op in insns:
        m = mn.split(".")[0]
        if mn in (".byte",):
            toks = [t.strip() for t in op.split(",")]
            clean = []
            for t in toks:
                t = t[2:] if t.lower().startswith("0x") else t.lstrip("$")
                clean.append("$" + t)
            result.append("\tdc.b\t%s" % ",".join(clean))
            marks.append((addr, size, len(result) - 1))
            continue
        if mn.startswith(".") or mn in ("dc.w",):
            toks = [t.strip().lstrip("$") for t in op.split(",")]
            clean = []
            for t in toks:
                try:
                    v = int(t, 16)
                    clean.append("$%04x" % v if v > 0xFF else "$%02x" % v)
                except ValueError:
                    clean.append(t)
            result.append("\tdc.w\t%s" % ",".join(clean))
            marks.append((addr, size, len(result) - 1))
            continue
        if addr in targets:
            result.append(".L%04X:" % addr)
        main_idx = len(result)
        pc_rel = "(pc)" in op
        if (m in COND or m in ("bsr",) or (m in ("jmp", "lea") and pc_rel)) \
                and op.strip().startswith("$"):
            try:
                t = int(op.strip()[1:].split(",")[0].split("(")[0].split()[0], 16)
            except ValueError:
                t = None
            if t is not None and 0 <= t < n:
                result.append("\t%s\t.L%04X" % (mn, t))
                marks.append((addr, size, main_idx))
                continue
            result.append("\tdc.w\t%s" % ",".join(
                "$%04x" % struct.unpack_from(">H", data, a)[0]
                for a in range(addr, addr + size, 2)))
            marks.append((addr, size, main_idx))
            continue
        if m in ("jmp", "jsr", "lea"):
            # forma assoluta (non pc-rel): byte letterali, mai label
            result.append("\tdc.w\t%s" % ",".join(
                "$%04x" % struct.unpack_from(">H", data, a)[0]
                for a in range(addr, addr + size, 2)))
            marks.append((addr, size, main_idx))
            continue
        if m in ("btst", "bset", "bclr", "bchg"):
            parts = op.split(",")
            if len(parts) == 2 and re.match(r"^d[0-7]$", parts[1].strip()):
                # dest registro: size sempre .l (il .b vale solo per memoria)
                result.append("\t%s.l\t%s" % (m, norm_op(op)))
                marks.append((addr, size, main_idx))
                continue
        result.append("\t%s\t%s" % (mn, fix_abs_operand(norm_op(op))) if op else "\t%s" % mn)
        marks.append((addr, size, main_idx))
    return result, marks


def assemble(src_path, out_path, vasm):
    p = subprocess.run([vasm, "-Fhunk", "-m68000", src_path, "-o", out_path],
                       capture_output=True, text=True, timeout=120)
    return p.returncode == 0 and os.path.isfile(out_path), (p.stdout or "") + (p.stderr or "")


def parse_listing(lst_path):
    """Ritorna {addr: indice_riga_sorgente} dal listing vasm (-L).

    Formato riga: '00:000001B8 4CDF7FFF  \t   128: \tmovem...'.
    """
    import re
    mapping = {}
    try:
        for line in open(lst_path, errors="replace"):
            m = re.match(r"[0-9A-Fa-f]+:([0-9A-Fa-f]+) [0-9A-Fa-f]+ +\t\s*(\d+):", line)
            if m:
                mapping[int(m.group(1), 16)] = int(m.group(2))
    except OSError:
        pass
    return mapping


def dc_line(data, addr, size):
    return "\tdc.w\t%s" % ",".join(
        "$%04x" % struct.unpack_from(">H", data, a)[0]
        for a in range(addr, addr + size, 2))


def reassemble_unit(name, target_path, asm_path, build_path, vasm, max_rounds=4,
                    force=False):
    data = open(target_path, "rb").read()
    if os.path.isfile(asm_path) and not force:
        return "skip-esistente", None
    lines, marks = render(data, name)
    header = ("; %s -- generato da tools/reasm.py, da rinominare/rifattorizzare.\n"
              "; 'opt o-' e dc.w garantiscono byte-identicita'; rivedere i dc.w.\n" % name)
    lst_path = build_path + ".lst"
    matched, total = 0, len(data)
    for rnd in range(max_rounds):
        with open(asm_path, "w") as f:
            f.write(header + "\n".join(lines) + "\n")
        p = subprocess.run(
            [vasm, "-Fhunk", "-m68000", "-L", lst_path, asm_path, "-o", build_path],
            capture_output=True, text=True, timeout=120)
        if p.returncode != 0 or not os.path.isfile(build_path):
            # errore assemble: riga indicata -> dc.w di pari lunghezza
            m = re.search(r"line (\d+)", (p.stdout or "") + (p.stderr or ""))
            if not m:
                return "assemble-error", ((p.stdout or "") + (p.stderr or ""))[-800:]
            errline = int(m.group(1))
            fixed = False
            # errline e' 1-based sul file (2 righe header + labels incluse
            # negli idx): idx+3 == errline, con tolleranza +-1
            for (addr, size, idx) in marks:
                if idx + 2 <= errline <= idx + 4:
                    lines[idx] = dc_line(data, addr, size)
                    fixed = True
                    break
            if not fixed:
                return "assemble-error", ((p.stdout or "") + (p.stderr or ""))[-800:]
            continue
        payload = diff_m68k.hunk_unit_payload(open(build_path, "rb").read())
        if payload is None:
            return "no-payload", None
        b = diff_m68k._rstrip_pad(payload, len(data))
        matched, total, _ = diff_m68k.compare_bytes(data, b)
        if matched == total and len(b) == len(data):
            return "ok-100", None
        # fallback: righe che coprono byte divergenti -> dc.w (stessa lunghezza)
        mapping = parse_listing(lst_path)
        divs = [i for i in range(min(len(data), len(b))) if data[i] != b[i]]
        if len(b) != len(data):
            divs += list(range(min(len(data), len(b)), max(len(data), len(b))))
        addrs = sorted(mapping)
        aside = set()
        changed = 0
        for off in divs:
            cand = [a for a in addrs if a <= off]
            if not cand:
                continue
            if mapping[cand[-1]] in aside:
                continue
            aside.add(mapping[cand[-1]])
            for (addr, size, idx) in marks:
                if addr <= off < addr + size and idx < len(lines):
                    if not lines[idx].strip().startswith("dc.w"):
                        lines[idx] = dc_line(data, addr, size)
                        changed += 1
                    break
        if changed == 0:
            return "parziale", "%d/%d" % (matched, total)
    return "parziale", "%d/%d" % (matched, total)


def dc_fallback(lines, data, base_payload):
    """Trova offset divergenti e converte la riga vasm corrispondente in dc.w.

    Mappa offset->riga tramite riassemblaggio incrementale: per ogni riga
    istruzione, assembla il file troncato e misura la lunghezza prodotta.
    Semplificazione robusta: sostituisce le righe sospette note
    (assoluti senza .l, move #imm,(An),_cmp senza opt) con dc.w.
    """
    # Strategia semplice e convergente: per ogni riga istruzione che contiene
    # un assoluto o immediato, prova a sostituirla con dc.w e tiene la
    # sostituzione se i byte di quella regione diventano uguali.
    return lines  # v1: il faithful rendering basta; hook per round futuri


def main(argv=None):
    ap = argparse.ArgumentParser(description="Riassembla slice in vasm byte-identico")
    ap.add_argument("--func", default=None)
    ap.add_argument("--all", action="store_true", dest="all_units")
    ap.add_argument("--units", default="config/units.json")
    ap.add_argument("--asm-dir", default="asm")
    ap.add_argument("--build-dir", default="build")
    ap.add_argument("--src-dir", default="src")
    ap.add_argument("--force", action="store_true",
                    help="rigenera anche asm/*.s esistenti (mai src/*.c)")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()

    vasm = find_vasm()
    if vasm is None:
        print("vasm non trovato (PATH o .toolchain); SKIP")
        return 0

    if a.func:
        units = [u for u in json.load(open(a.units))["units"] if u["name"] == a.func]
    else:
        units = json.load(open(a.units))["units"]
    done, matched = 0, 0
    for u in units:
        name = u["name"]
        asm_p = os.path.join(a.asm_dir, name + ".s")
        if os.path.isfile(os.path.join(a.src_dir, name + ".c")):
            continue
        if os.path.isfile(asm_p):
            if not a.force:
                continue
            head = open(asm_p, encoding="utf-8", errors="replace").read(400)
            if "generato da tools/reasm.py" not in head:
                print("  %-20s skip-manuale" % name)
                continue
        tp = u["target"]
        if not tp or not os.path.isfile(tp):
            continue
        st, info = reassemble_unit(name, tp, asm_p,
                                   os.path.join(a.build_dir, name + ".o"), vasm,
                                   force=a.force)
        print("  %-20s %s %s" % (name, st, info or ""))
        done += 1
        if st == "ok-100":
            matched += 1
    print("riassemblate: %d, al 100%%: %d" % (done, matched))
    return 0


def self_test():
    print("== reasm.py self-test ==")
    vasm = find_vasm()
    if vasm is None:
        print("  SKIP: vasmm68k_mot non trovato")
        return 0
    import tempfile
    with tempfile.TemporaryDirectory() as d:
        # bra.s +4 (salta 2 nop) | nop | nop | rts | move.w #$8,$dff09c | dati
        code = bytes.fromhex("60044e714e714e7533fc000800dff09caabb")
        tp = os.path.join(d, "t.bin")
        open(tp, "wb").write(code)
        lines, _marks = render(code, "tfunc")
        src = "\n".join(lines)
        assert ".L" in src and "bra" in src, src
        assert "dc.b" in src or "dc.w" in src, src
        ap_ = os.path.join(d, "t.s")
        open(ap_, "w").write(src + "\n")
        out = os.path.join(d, "t.o")
        ok, log = assemble(ap_, out, vasm)
        assert ok, log[-500:]
        p = diff_m68k._rstrip_pad(diff_m68k.hunk_unit_payload(open(out, "rb").read()), len(code))
        m, tot, _ = diff_m68k.compare_bytes(code, p)
        assert (m, tot) == (len(code), len(code)) and len(p) == len(code), (m, tot, len(p))
        print("  [ok] branch+assoluto+dati -> 100% (label+dc present)")
        # render non tocca file esistenti
        st, _ = reassemble_unit("tfunc", tp, ap_, out, vasm)
        assert st == "skip-esistente", st
        print("  [ok] non sovrascrive sorgenti esistenti")
    print("ALL SELF-TESTS PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())
