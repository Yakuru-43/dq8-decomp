#!/usr/bin/env python3
"""Relabel an object's MIPS ABI in e_flags as O64 so ld will link it with the asm objects.

mwccps2 marks objects EABI64; gas needs -mabi=o64 to accept spimdisasm's o32-style
register names. Only the header label differs, the code is untouched.
"""
import struct
import sys

EF_MIPS_ABI = 0x0000F000
EF_MIPS_ABI_O64 = 0x00002000

with open(sys.argv[1], "r+b") as f:
    f.seek(0x24)
    flags = struct.unpack("<I", f.read(4))[0]
    f.seek(0x24)
    f.write(struct.pack("<I", (flags & ~EF_MIPS_ABI) | EF_MIPS_ABI_O64))
