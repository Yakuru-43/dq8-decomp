#!/usr/bin/env python3
"""Compile a C/C++ snippet with mwccps2 and compare one function to the original.

    try_match.py <file.c|.cpp> <symbol> <vram> [--bin SLES_539.74] [--ver 2.4-001213] [-- flags...]

Prints MATCH or the first differing instruction. Use it to pin compiler
versions/flags and to check a decompiled function before adding it to src/.
"""
import argparse
import struct
import subprocess
import sys
import tempfile
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
    for i, (m, o) in enumerate(zip(words(mine), words(orig))):
        kind = rel.get(start + i * 4)
        # relocated fields hold unresolved addresses in the object: mask them
        mask = 0xFC000000 if kind == "R_MIPS_26" else 0xFFFF0000 if kind else 0xFFFFFFFF
        if (m ^ o) & mask:
            print(f"DIFF at +0x{i * 4:X}: mine {m:08X} orig {o:08X}  ({len(mine)} bytes)")
            return 1
    print(f"MATCH ({len(mine)} bytes, {a.ver} {' '.join(a.flags)})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
