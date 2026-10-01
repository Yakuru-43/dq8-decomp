#!/usr/bin/env python3
"""Set up (and optionally run) decomp-permuter for one function.

    permute.py <func> [--bin SLES_539.74] [--run SECONDS] [-j N]

Creates build/permute/<func>/ with base.c (best m2c draft from autodecomp,
common.h inlined), target.o (the original asm), compile.sh and settings.toml.
The permuter lives in .toolchain/permuter
(git clone https://github.com/simonlindholm/decomp-permuter .toolchain/permuter).
Results land in build/permute/<func>/output-<score>-<n>/; score 0 is a match,
which still has to be checked with autodecomp-style verification before use.
"""
import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp as a  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--run", type=int, help="run the permuter for this many seconds")
    ap.add_argument("-j", type=int, default=4)
    args = ap.parse_args()

    f = next((x for x in a.functions(args.bin) if x[0] == args.func), None)
    if not f:
        sys.exit(f"{args.func} not found in asm/{args.bin} (already in src/?)")
    draft = next(a.candidates(f[0], f[3]), None)
    if not draft:
        sys.exit("m2c could not draft this function; write base.c by hand")

    d = ROOT / "build" / "permute" / args.func
    d.mkdir(parents=True, exist_ok=True)
    c = draft[1].replace('#include "common.h"', (ROOT / "include/common.h").read_text())
    (d / "base.c").write_text(c)
    (d / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + f[3])
    subprocess.run([a.BIN / "mips64-linux-gnu-as", "-EL", "-march=r5900", "-mabi=o64", "-G0",
                    "-no-pad-sections", "-I", ROOT / "include", d / "target.s", "-o", d / "target.o"], check=True)
    (d / "compile.sh").write_text(
        f'#!/bin/sh\nexec "{a.TC / "wibo"}" "{a.MWCC}" -c {" ".join(a.CFLAGS)} "$1" -o "$3"\n')
    (d / "compile.sh").chmod(0o755)
    (d / "settings.toml").write_text(
        f'func_name = "{args.func}"\ncompiler_type = "mwcc"\n'
        f'objdump_command = "{a.BIN / "mips64-linux-gnu-objdump"} -drz -m mips:5900"\n')
    print(d)

    if args.run:
        permuter = ROOT / ".toolchain" / "permuter" / "permuter.py"
        subprocess.run(["timeout", str(args.run), sys.executable, permuter, d, "--stop-on-zero", "-j", str(args.j)])


if __name__ == "__main__":
    main()
