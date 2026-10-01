#!/usr/bin/env python3
"""Adjust splat's linker scripts after a split.

Compiled objects carry no trailing padding, so pad each one's .text to the next
16-byte boundary (where the following function starts; autodecomp checks this).
"""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
for ld in (ROOT / "linker").glob("*.ld"):
    text = ld.read_text()
    new = re.sub(r"^(\s+)(build/src/\S+\.o\(\.text\);)$", r"\1\2\n\1. = ALIGN(., 16);", text, flags=re.M)
    if new != text:
        ld.write_text(new)
