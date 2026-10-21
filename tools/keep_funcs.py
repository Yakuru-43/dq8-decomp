#!/usr/bin/env python3
"""Keep a glabel for every function that decompiled code calls.

A new src/<bin>/<func>.c truncates the asm chunk that used to cover it, and
splat re-disassembles what is left with its own heuristics.  Those can merge
neighbours into one function and drop the glabel in between, which turns into
`undefined reference to func_0046A510` at link time even though no byte
changed.  So ask the linker script which objects make up each binary, take the
function symbols the compiled files still need and nothing in the link
provides, and give each one a `type:func` entry in
config/symbol_addrs_<bin>.txt: splat starts a function at every such symbol,
so the label survives the next re-split as well.

    keep_funcs.py [--dry-run]

Run after a build (it reads build/ objects and linker/*.ld); if it adds
anything, `make split && make -j` again.
"""
import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp as a  # noqa: E402
from gen_configs import MAIN_TEXT_REGIONS  # noqa: E402

BINARIES = ["SLES_539.74", "TITLE", "SHOP", "MENU", "CASINO", "BATTLE"]
FUNC = re.compile(r"func_([0-9A-Fa-f]{8})")
BLOCK = "// --- labels kept for calls from decompiled code (tools/keep_funcs.py) ---"
NM = str(a.BIN / "mips64-linux-gnu-nm")


def text_ranges(binary):
    """[(start, end)] vram spans covered by this binary's own .text."""
    if binary != "SLES_539.74":
        head = (ROOT / "extract" / f"{binary}.head").read_bytes()
        _, _, vram, text, _, _ = struct.unpack_from("<4sIIIII", head)
        vram += len(head)  # code follows the 0x40-byte header (gen_configs.overlay_yaml)
        return [(vram, vram + text)]
    return [(start, end) for (start, _), (end, next_prefix)
            in zip(MAIN_TEXT_REGIONS, MAIN_TEXT_REGIONS[1:]) if next_prefix]


def nm_names(flags, files):
    """Symbol names in `files`, from `nm -A` (which skips what is not built)."""
    names = set()
    files = [str(f) for f in files if f.exists()]
    for i in range(0, len(files), 400):
        r = subprocess.run([NM, "-A", *flags, *files[i:i + 400]],
                           capture_output=True, text=True)
        for line in (r.stdout + r.stderr).splitlines():
            _, _, rest = line.partition(":")  # nm prefixes each line with its object
            t = rest.split()
            if len(t) == 3:        # path: value type name
                names.add(t[2])
            elif len(t) == 2:      # path: U name
                names.add(t[1])
    return names


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    total = 0
    for binary in BINARIES:
        ld = ROOT / "linker" / f"{binary}.ld"
        if not ld.exists():
            continue
        objs = [ROOT / p for p in re.findall(r"(build/\S+\.o)", ld.read_text())]
        src_objs = [o for o in objs if o.is_relative_to(ROOT / "build" / "src" / binary)]
        provided = nm_names(["--defined-only"], objs)
        for auto in (f"{binary}_undefined_funcs_auto.txt", f"{binary}_undefined_syms_auto.txt"):
            f = ROOT / "linker" / auto
            if f.exists():  # absolute symbols the link borrows from other binaries
                provided |= set(re.findall(r"^(\w+) = ", f.read_text(), re.M))

        ranges = text_ranges(binary)
        missing = sorted({int(m.group(1), 16) for n in nm_names(["--undefined-only"], src_objs)
                          - provided for m in [FUNC.fullmatch(n)] if m
                          if any(s <= int(m.group(1), 16) < e for s, e in ranges)})
        if not missing:
            continue
        print(f"{binary}: {len(missing)} call target(s) without a label: "
              + " ".join(f"0x{x:X}" for x in missing))
        total += len(missing)
        if args.dry_run:
            continue
        manual = ROOT / "config" / f"symbol_addrs_{binary}.txt"
        have = manual.read_text() if manual.exists() else ""
        head = have[: have.index(BLOCK)] if BLOCK in have else have
        block = have[have.index(BLOCK):] if BLOCK in have else ""
        keep = sorted({int(m.group(1), 16) for m in
                       re.finditer(r"^func_([0-9A-Fa-f]{8}) =", block, re.M)} | set(missing))
        manual.write_text(head.rstrip("\n") + "\n\n" + BLOCK + "\n"
                          + "".join(f"func_{x:08X} = 0x{x:X}; // type:func\n" for x in keep))
    print(f"{total} label(s) to keep"
          + (" (dry run)" if args.dry_run else "; re-run `make split && make -j`"))


if __name__ == "__main__":
    main()
