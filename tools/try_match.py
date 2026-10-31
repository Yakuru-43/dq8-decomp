#!/usr/bin/env python3
"""Compile a C/C++ snippet with mwccps2 and compare one function to the original.

    try_match.py <file.c|.cpp> <symbol> <vram> [--bin SLES_539.74] [--ver 2.4-001213] [-- flags...]

Prints MATCH, or the first differing instruction and a CLASS line (register-only,
reorder-only, reorder+register or structural, with a score; 0 = match). Use it to pin compiler
versions/flags and to check a decompiled function before adding it to src/.
"""
import argparse
import os
import struct
import subprocess
import sys
import tempfile
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TC = ROOT / ".toolchain"
VRAM = {"SLES_539.74": 0x100000}  # overlays: 0x45ECC0


def relocs(obj):
    """{text offset: reloc type} for .text."""
    out = {}
    r = subprocess.run([TC / "usr/bin/mips64-linux-gnu-readelf", "-rW", obj], capture_output=True, text=True).stdout
    section = None
    for line in r.splitlines():
        if line.startswith("Relocation section"):
            section = line.split("'")[1]
        elif section == ".rela.text" or section == ".rel.text":
            p = line.split()
            if len(p) >= 3 and p[2].startswith("R_MIPS"):
                out[int(p[0], 16)] = p[2]
    return out


def func_bytes(obj, symbol):
    """(offset, bytes) of `symbol` from a relocatable object."""
    nm = subprocess.run([TC / "usr/bin/mips64-linux-gnu-nm", "-S", obj], capture_output=True, text=True).stdout
    for line in nm.splitlines():
        p = line.split()
        if len(p) == 4 and p[3] == symbol:
            off, size = int(p[0], 16), int(p[1], 16)
            break
    else:
        sys.exit(f"{symbol} not found in object:\n{nm}")
    text = Path(obj + ".text")
    subprocess.run([TC / "usr/bin/mips64-linux-gnu-objcopy", "-O", "binary", "-j", ".text", obj, text], check=True)
    return off, text.read_bytes()[off:off + size]


def spend_budget(symbol, budget):
    """Count an attempt on `symbol`; past the budget ("ATTEMPTS,SECONDS"), refuse it.

    Set by run.sh for the factory sessions only. A session told to stop after 20
    attempts or 25 minutes kept going on one function until the session was cut off
    (2026-10-28..31: 9-16 sessions per slice in 72 h finished nothing), so the limit
    is kept here, from the first attempt on the function in this session
    (build/budget.tsv, cleared by run.sh at the session's start).
    """
    attempts, seconds = (int(x) for x in budget.split(","))
    state = ROOT / "build" / "budget.tsv"
    rows = {}
    if state.exists():
        for line in state.read_text().splitlines():
            name, first, n = line.split("\t")
            rows[name] = (float(first), int(n))
    first, n = rows.get(symbol, (time.time(), 0))
    spent_min = (time.time() - first) / 60
    if n >= attempts or spent_min * 60 >= seconds:
        sys.exit(f"BUDGET SPENT on {symbol}: {n} attempts, {spent_min:.0f} min. Stop here: write the "
                 f"needs-claude note (the CLASS line of your best attempt first), set the row to "
                 f"needs-claude and claim the next one.")
    rows[symbol] = (first, n + 1)
    state.parent.mkdir(exist_ok=True)
    state.write_text("".join(f"{k}\t{f}\t{c}\n" for k, (f, c) in rows.items()))
    print(f"attempt {n + 1}/{attempts} on {symbol}, {spent_min:.0f}/{seconds // 60} min")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("symbol")
    ap.add_argument("vram", type=lambda x: int(x, 0))
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--ver", default="3.0.1b151-050317")
    ap.add_argument("--show", action="store_true", help="print both disassemblies side by side")
    ap.add_argument("flags", nargs="*", default=["-O2"])
    a = ap.parse_args()
    if os.environ.get("DQ8_BUDGET") and not a.show:
        spend_budget(a.symbol, os.environ["DQ8_BUDGET"])

    base = VRAM.get(a.bin, 0x45ECC0)
    orig_all = (ROOT / "extract" / f"{a.bin}.bin").read_bytes()
    with tempfile.TemporaryDirectory() as tmp:
        obj = f"{tmp}/out.o"
        r = subprocess.run([TC / "wibo", TC / "mwcps2" / a.ver / "mwccps2.exe", "-c", *a.flags,
                            "-nostdinc", "-stderr", f"-I{ROOT / 'include'}", a.src, "-o", obj], capture_output=True, text=True)
        if r.returncode:
            sys.exit(r.stdout + r.stderr)
        start, mine = func_bytes(obj, a.symbol)
        rel = relocs(obj)
    orig = orig_all[a.vram - base:a.vram - base + len(mine)]
    words = lambda b: struct.unpack(f"<{len(b) // 4}I", b)
    if a.show:
        import rabbitizer
        dis = lambda w, va: rabbitizer.Instruction(w, vram=va, category=rabbitizer.InstrCategory.R5900).disassemble()
        for i, (m, o) in enumerate(zip(words(mine), words(orig))):
            mark = " " if m == o else "*"
            print(f"{mark} +{i * 4:03X}  {dis(m, a.vram + i * 4):<34} {dis(o, a.vram + i * 4)}")
    first = None
    masked = []
    for i, (m, o) in enumerate(zip(words(mine), words(orig))):
        kind = rel.get(start + i * 4)
        # relocated fields hold unresolved addresses in the object: mask them
        mask = 0xFC000000 if kind == "R_MIPS_26" else 0xFFFF0000 if kind else 0xFFFFFFFF
        masked.append((m & mask, o & mask, m, o))
        if (m ^ o) & mask and first is None:
            first = i
            print(f"DIFF at +0x{i * 4:X}: mine {m:08X} orig {o:08X}  ({len(mine)} bytes)")
    if first is None and len(mine) == len(orig):
        print(f"MATCH ({len(mine)} bytes, {a.ver} {' '.join(a.flags)})")
        return 0
    if first is None:
        print(f"DIFF at +0x{len(orig) and min(len(mine), len(orig)):X}: size {len(mine)} vs {len(orig)} bytes")
    print(classify(masked, len(mine), orig_size(a.src, orig_all, base, len(orig)), a.vram))
    return 1


def orig_size(src, orig_all, base, fallback):
    """The original function's size from the file's `// range:` line, without the
    alignment nops at its end; the compared length when there is no range line."""
    import csv, re
    lo = hi = None
    db = ROOT / "build" / "funcdb.tsv"     # the split's own bounds, when known
    name = re.search(r"func_[0-9A-F]{8}", Path(src).name)
    if db.exists() and name:
        for row in csv.DictReader(open(db), delimiter="\t"):
            if row["func"] == name.group(0):
                lo = int(row["addr"], 16)
                hi = lo + int(row["size"])
                break
    if lo is None:
        m = re.search(r"//\s*range:\s*0x([0-9A-Fa-f]+)\s+0x([0-9A-Fa-f]+)", Path(src).read_text(errors="replace"))
        if not m:
            return fallback
        lo, hi = int(m.group(1), 16), int(m.group(2), 16)
    body = orig_all[lo - base:hi - base]
    n = len(body)
    while n >= 4 and body[n - 4:n] == b"\0\0\0\0":
        n -= 4
    # a nop right after a jump is its delay slot, not padding
    if n >= 4 and n < len(body) and (int.from_bytes(body[n - 4:n], "little") >> 26 in (2, 3)
                                      or int.from_bytes(body[n - 4:n], "little") & 0xFC00003E == 8):
        n += 4
    return n


def classify(masked, n_mine, n_orig, vram):
    """One line for notes and routing: the kind of mismatch, and a score
    (differing words + size difference in words; 0 = match).
      register-only     same instruction at every position, only registers differ
      reorder-only      the same instructions, in a different order
      reorder+register  the same mnemonics overall, in a different order and registers
      structural        anything else (other instructions, other size)"""
    import rabbitizer
    def parts(w, i):
        text = rabbitizer.Instruction(w, vram=vram + i * 4, category=rabbitizer.InstrCategory.R5900).disassemble()
        mnem, _, ops = text.strip().partition(" ")
        return mnem, [t for t in ops.replace("(", ",").replace(")", "").split(",") if t.strip()]
    diff = sum(1 for mm, oo, _, _ in masked if mm != oo)
    score = diff + abs(n_mine - n_orig) // 4
    if n_mine != n_orig:
        kind = "structural"
    elif sorted(x[0] for x in masked) == sorted(x[1] for x in masked):
        kind = "reorder-only"
    else:
        pm = [parts(m, i) for i, (_, _, m, _) in enumerate(masked)]
        po = [parts(o, i) for i, (_, _, _, o) in enumerate(masked)]
        regs_only = lambda a, b: a[0] == b[0] and len(a[1]) == len(b[1]) and all(
            x == y or (x.strip().startswith("$") and y.strip().startswith("$")) for x, y in zip(a[1], b[1]))
        if all(regs_only(a, b) for a, b in zip(pm, po)):
            kind = "register-only"
        elif sorted(x[0] for x in pm) == sorted(x[0] for x in po):
            kind = "reorder+register"
        else:
            kind = "structural"
    return f"CLASS {kind} score={score} ({diff} words differ, {n_mine} vs {n_orig} bytes)"


if __name__ == "__main__":
    sys.exit(main())
