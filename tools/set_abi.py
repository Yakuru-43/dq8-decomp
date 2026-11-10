#!/usr/bin/env python3
"""Fix up an mwccps2 object so GNU ld links it the way CodeWarrior's linker would.

1. Relabel the MIPS ABI in e_flags as O64 so ld will link it with the asm objects.
   mwccps2 marks objects EABI64; gas needs -mabi=o64 to accept spimdisasm's o32-style
   register names. Only the header label differs, the code is untouched.
2. Dead-strip unused C++ inline functions. mwccps2 emits every inline member that
   needs an out-of-line copy (e.g. the deleting destructor `__dt__8SemaLockFv` of a
   scoped lock whose calls were all inlined) in its own `.text` section, with symbol
   binding 13 (multiply defined). CodeWarrior's linker drops such a function when
   nothing calls it; GNU ld would place it in the binary. A section like that which
   no relocation of the object's code or data points at is emptied, with its
   relocations and its `.mwcats` entry. Binding 13 becomes weak, so the copies in
   several objects don't clash.

Run it before any `ld -r` (the Makefile's rodata merge): that merges the `.text`
sections into one and the dead function can't be told apart any more.
"""
import struct
import sys

EF_MIPS_ABI = 0x0000F000
EF_MIPS_ABI_O64 = 0x00002000

SHT_SYMTAB, SHT_RELA, SHT_REL = 2, 4, 9
SHF_ALLOC, SHF_EXECINSTR = 0x2, 0x4
STB_WEAK, STB_MULTIDEF, STT_FUNC = 2, 13, 2
SH = struct.Struct("<10I")  # name type flags addr offset size link info addralign entsize


def sections(data):
    shoff, = struct.unpack_from("<I", data, 0x20)
    shnum, = struct.unpack_from("<H", data, 0x30)
    return [list(SH.unpack_from(data, shoff + i * SH.size)) for i in range(shnum)], shoff


def unused_inlines(data, secs):
    """Indexes of the executable sections that only hold an uncalled multidef function."""
    symtab = next(s for s in secs if s[1] == SHT_SYMTAB)
    syms = [struct.unpack_from("<IIIBBH", data, symtab[4] + i * 16) for i in range(symtab[5] // 16)]
    owners = {}  # section index: the binding of every function defined in it
    for name, value, size, info, other, shndx in syms:
        if info & 0xF == STT_FUNC:
            owners.setdefault(shndx, []).append(info >> 4)
    candidates = {i for i, binds in owners.items()
                  if 0 < i < len(secs) and secs[i][2] & SHF_EXECINSTR
                  and all(b == STB_MULTIDEF for b in binds)}
    for s in secs:
        if s[1] not in (SHT_REL, SHT_RELA) or not secs[s[7]][2] & SHF_ALLOC:
            continue
        step = 8 if s[1] == SHT_REL else 12
        for off in range(s[4], s[4] + s[5], step):
            r_info, = struct.unpack_from("<I", data, off + 4)
            sym = syms[r_info >> 8]
            if s[7] != sym[5]:
                candidates.discard(sym[5])  # a call or address from elsewhere keeps it
    return candidates


def main():
    with open(sys.argv[1], "rb") as f:
        data = bytearray(f.read())
    flags, = struct.unpack_from("<I", data, 0x24)
    struct.pack_into("<I", data, 0x24, (flags & ~EF_MIPS_ABI) | EF_MIPS_ABI_O64)

    secs, shoff = sections(data)
    dead = unused_inlines(data, secs)
    dead |= {i for i, s in enumerate(secs) if s[6] in dead and not s[2] & SHF_ALLOC}  # its .mwcats
    for i, s in enumerate(secs):
        if i in dead or (s[1] in (SHT_REL, SHT_RELA) and s[7] in dead):
            s[5] = 0
            if i in dead:
                s[8] = 1
            SH.pack_into(data, shoff + i * SH.size, *s)
    # GNU ld reads binding 13 as global, so two objects with the same inline copy
    # clash; multidef means "keep one", which is ELF's weak
    symtab = next(s for s in secs if s[1] == SHT_SYMTAB)
    for off in range(symtab[4], symtab[4] + symtab[5], 16):
        if data[off + 12] >> 4 == STB_MULTIDEF:
            data[off + 12] = STB_WEAK << 4 | data[off + 12] & 0xF
    with open(sys.argv[1], "wb") as f:
        f.write(data)


if __name__ == "__main__":
    main()
