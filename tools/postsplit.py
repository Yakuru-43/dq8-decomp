#!/usr/bin/env python3
"""Adjust splat's linker scripts after a split.

Compiled objects carry no trailing padding, so pad each one's .text to the next
16-byte boundary (where the following function starts; autodecomp checks this).

A src file with a `// rodata: 0xSTART 0xEND` line (a switch's jump table) has
its .rodata linked inside the data segment, where gen_configs cut that range
out. splat lists it twice -- once among its own segment's .rodata, which comes
first and would win, and once at the end of the data segment, after every
.data -- so both lines are replaced by one right after the data file that
precedes START.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from gen_configs import src_rodata  # noqa: E402

DATA_OBJ = re.compile(r"^\s+build/asm/\S+/data/data_([0-9A-F]{6,8})\.data\.s\.o\(\.data\);$")


def place_rodata(text, binary):
    lines = text.split("\n")
    prev = None  # (start, line index) of the last placed .rodata
    for start, end, name in src_rodata(binary):
        pat = re.compile(rf"^(\s+)(build/src/{re.escape(binary)}/{re.escape(name)}\.c(?:pp)?\.o)\(\.rodata\);$")
        found = [(i, m) for i, m in ((i, pat.match(ln)) for i, ln in enumerate(lines)) if m]
        if not found:
            continue
        indent, obj = found[0][1].group(1), found[0][1].group(2)
        for i, _ in reversed(found):
            del lines[i]
            if prev and i <= prev[1]:
                prev = (prev[0], prev[1] - 1)
        anchor, at = None, -1
        for i, ln in enumerate(lines):
            m = DATA_OBJ.match(ln)
            if m and at < int(m.group(1), 16) < start:
                anchor, at = i, int(m.group(1), 16)
        if prev and prev[0] > at:
            anchor = prev[1]
        if anchor is None:
            sys.exit(f"postsplit: no data file before 0x{start:X} for {name}")
        lines.insert(anchor + 1, f"{indent}{obj}(.rodata);")
        prev = (start, anchor + 1)
    return "\n".join(lines)


for ld in (ROOT / "linker").glob("*.ld"):
    text = ld.read_text()
    new = re.sub(r"^(\s+)(build/src/\S+\.o\(\.text\);)$", r"\1\2\n\1. = ALIGN(., 16);", text, flags=re.M)
    new = place_rodata(new, ld.stem)
    if new != text:
        ld.write_text(new)
