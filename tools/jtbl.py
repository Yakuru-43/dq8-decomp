#!/usr/bin/env python3
"""What a function with a jump table needs: its `// rodata:` line and an m2c draft.

    jtbl.py func_XXXXXXXX [--bin SLES_539.74] [--m2c] [--diff src/<bin>/<file>.c]

Prints the `// rodata: 0xSTART 0xEND` line the src file must carry under its
`// range:` line (the jump tables the function uses, as they sit in the data
segment), and with --m2c the m2c draft from the function's asm plus its tables,
so the draft has a real `switch` instead of `goto *jtbl[...]`.
tools/verify.py then checks the tables too; when it says RODATA (the code
matches, the table not), --diff prints the entries that differ: each one is a
case value your switch sends somewhere else (often a missing `case N: break;`).
"""
import argparse
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from autodecomp import (VRAM, functions, rodata_range, symbol_script, verify,  # noqa: E402
                        with_jump_tables)

ROOT = Path(__file__).resolve().parent.parent


def table_diff(binary, path, span):
    """Print the table entries the src file at `path` gets wrong."""
    c = Path(path).read_text()
    rng = re.search(r"^// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", c, re.M)
    flags = re.search(r"^// flags: (.*)$", c, re.M)
    start, end = int(rng.group(1), 16), int(rng.group(2), 16)
    base = VRAM.get(binary, 0x45ECC0)
    data = (ROOT / "extract" / f"{binary}.bin").read_bytes()
    syms = ROOT / "build" / f"{binary}_all_syms.ld"
    symbol_script(binary, syms)
    orig = data[span[0] - base:span[1] - base]
    got = {}
    why = verify(c, start, end, syms, data[start - base:end - base],
                 tuple(flags.group(1).split()) if flags else (), Path(path).suffix,
                 (span[0], orig), got)
    print(f"verify: {why}")
    mine = got.get("rodata")
    if mine is None:
        return
    if len(mine) != len(orig):
        print(f"table size {len(mine)} bytes, original {len(orig)}")
    words = lambda b: struct.unpack(f"<{len(b) // 4}I", b[:len(b) // 4 * 4])
    for i, (m, o) in enumerate(zip(words(mine), words(orig))):
        if m != o:
            print(f"entry {i}: yours -> +0x{m - start:X}, original -> +0x{o - start:X}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--m2c", action="store_true", help="also print the m2c draft")
    ap.add_argument("--diff", metavar="SRC", help="compare SRC's table with the original")
    a = ap.parse_args()
    asm = next((x[3] for x in functions(a.bin) if x[0] == a.func), None)
    if asm is None:
        sys.exit(f"{a.func}: not in asm/{a.bin}")
    span = rodata_range(a.bin, asm)
    if span is None:
        sys.exit(f"{a.func}: uses no jump table")
    print(f"// rodata: 0x{span[0]:X} 0x{span[1]:X}")
    if a.diff:
        table_diff(a.bin, a.diff, span)
    if a.m2c:
        with tempfile.NamedTemporaryFile("w", suffix=".s") as t:
            t.write(with_jump_tables(a.bin, asm))
            t.flush()
            r = subprocess.run([str(Path(sys.executable).parent / "m2c"), "--valid-syntax", "--globals", "used",
                                "--no-cache", "-t", "mipsee-mwcc-c", "-f", a.func, t.name],
                               capture_output=True, text=True)
        print(r.stdout + r.stderr)


if __name__ == "__main__":
    main()
