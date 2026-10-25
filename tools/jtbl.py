#!/usr/bin/env python3
"""What a function with a jump table needs: its `// rodata:` line and an m2c draft.

    jtbl.py func_XXXXXXXX [--bin SLES_539.74] [--m2c]

Prints the `// rodata: 0xSTART 0xEND` line the src file must carry under its
`// range:` line (the jump tables the function uses, as they sit in the data
segment), and with --m2c the m2c draft from the function's asm plus its tables,
so the draft has a real `switch` instead of `goto *jtbl[...]`.
tools/verify.py then checks the tables too.
"""
import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from autodecomp import functions, rodata_range, with_jump_tables  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--m2c", action="store_true", help="also print the m2c draft")
    a = ap.parse_args()
    asm = next((x[3] for x in functions(a.bin) if x[0] == a.func), None)
    if asm is None:
        sys.exit(f"{a.func}: not in asm/{a.bin}")
    span = rodata_range(a.bin, asm)
    if span is None:
        sys.exit(f"{a.func}: uses no jump table")
    print(f"// rodata: 0x{span[0]:X} 0x{span[1]:X}")
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
