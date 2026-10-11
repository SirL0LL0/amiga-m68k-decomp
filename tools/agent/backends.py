"""Proponenti di varianti C per l'agent loop: euristiche deterministiche + LLM opzionale."""

import json
import os
import urllib.request

QUALIFIER_TOGGLES = [
    ("volatile CUSTOM", "CUSTOM"),
    ("CUSTOM", "volatile CUSTOM"),
]


def heuristic_variants(candidate_c, flag_sets, max_variants):
    """Ritorna [(label, source_c, flags)].

    v0: sweep su flag_sets x toggle volatile del puntatore CUSTOM.
    Solo trasformazioni che compilano: nessun cambio semantico oltre volatile.
    """
    variants = []
    seen = set()
    flag_list = flag_sets if flag_sets else [""]
    for flags in flag_list:
        for src in _qualifier_family(candidate_c):
            key = (src, flags)
            if key in seen:
                continue
            seen.add(key)
            variants.append(("flags=%r q=%s" % (flags, "v" if "volatile CUSTOM" in src else "-"),
                             src, flags))
            if len(variants) >= max_variants:
                return variants
    return variants


def _qualifier_family(candidate_c):
    fam = [candidate_c]
    if "volatile CUSTOM" in candidate_c:
        fam.append(candidate_c.replace("volatile CUSTOM", "CUSTOM"))
    elif "CUSTOM" in candidate_c:
        fam.append(candidate_c.replace("CUSTOM", "volatile CUSTOM", 1))
    return fam


def disasm_lines(target_bytes):
    try:
        from capstone import Cs, CS_ARCH_M68K, CS_MODE_BIG_ENDIAN
        md = Cs(CS_ARCH_M68K, CS_MODE_BIG_ENDIAN)
        return ["%04x: %-8s %s" % (i.address, i.mnemonic, i.op_str)
                for i in md.disasm(target_bytes, 0)]
    except Exception:
        return ["<%d bytes>" % len(target_bytes)]


def llm_proposals(candidate_c, target_bytes, base_bytes, score, cfg):
    """Proposte via API OpenAI-compatible. Ritorna [source_c]. Fallback: []."""
    api_key = os.environ.get(cfg.get("api_key_env", "OPENAI_API_KEY"), "")
    if not api_key:
        return []
    prompt = (
        "You are helping with a matching decompilation of Motorola 68000 code "
        "(Amiga game). Rewrite the C function below so that when compiled with "
        "vbcc for m68k-amigaos it assembles closer to the TARGET disassembly.\n"
        "Current match: %.1f%%.\n\nTARGET M68K:\n%s\n\nCURRENT C:\n%s\n\n"
        "Reply with ONLY a ```c fenced code block containing the full function."
    ) % (score, "\n".join(disasm_lines(target_bytes)), candidate_c)
    body = json.dumps({
        "model": cfg.get("model", "gpt-4o-mini"),
        "messages": [{"role": "user", "content": prompt}],
        "temperature": 0.2,
        "max_tokens": 2000,
    }).encode()
    req = urllib.request.Request(
        cfg.get("base_url", "https://api.openai.com/v1").rstrip("/") + "/chat/completions",
        data=body,
        headers={"Content-Type": "application/json",
                 "Authorization": "Bearer " + api_key})
    try:
        with urllib.request.urlopen(req, timeout=120) as r:
            data = json.load(r)
        text = data["choices"][0]["message"]["content"]
        return _extract_c_blocks(text)[:int(cfg.get("max_proposals", 2))]
    except Exception as e:
        print("  llm non disponibile (%s), solo euristiche" % e)
        return []


def _extract_c_blocks(text):
    blocks, cur, in_block = [], [], False
    for line in text.splitlines():
        if line.strip().startswith("```"):
            if in_block:
                blocks.append("\n".join(cur) + "\n")
                cur = []
            in_block = not in_block
            continue
        if in_block:
            cur.append(line)
    return [b for b in blocks if b.strip()]
