#!/usr/bin/env python3
"""Extract code payloads from the DQ8 PAL ISO (SLES-53974) for splat.

Main ELF: the single PT_LOAD payload (file offset 0x180, vram 0x100000) goes to
extract/SLES_539.74.bin; the bytes before/after it are kept so the build can
stitch a byte-identical ELF back together.

Overlays (BIN/*.BIN): "MWo3" header (0x40 bytes) followed by text+data.
"""
import hashlib
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ISO = ROOT / "DQ8.iso"
ISO_DIR = ROOT / "iso"
OUT = ROOT / "extract"

MAIN_SHA1 = "48ebb92638560447aab9c94235b0ebee5e93bc44"
OVERLAYS = ["TITLE", "SHOP", "MENU", "CASINO", "BATTLE"]


def sha1(data):
    return hashlib.sha1(data).hexdigest()


def main():
    if not (ISO_DIR / "SLES_539.74").exists():
        if not ISO.exists():
            sys.exit(f"missing {ISO}")
        subprocess.run(["7z", "x", "-y", f"-o{ISO_DIR}", str(ISO),
                        "SYSTEM.CNF", "SLES_539.74", "BIN/*", "MODULES/*",
                        "DATA.HD6", "DATA2.HD6"], check=True, stdout=subprocess.DEVNULL)

    OUT.mkdir(exist_ok=True)
    elf = (ISO_DIR / "SLES_539.74").read_bytes()
    if sha1(elf) != MAIN_SHA1:
        sys.exit("SLES_539.74 sha1 mismatch: only the PAL release (SLES-53974) is supported")

    phoff = struct.unpack_from("<I", elf, 0x1C)[0]
    _, off, vaddr, _, filesz, _, _, _ = struct.unpack_from("<8I", elf, phoff)
    assert (off, vaddr) == (0x180, 0x100000)
    (OUT / "SLES_539.74.head").write_bytes(elf[:off])
    (OUT / "SLES_539.74.bin").write_bytes(elf[off:off + filesz])
    (OUT / "SLES_539.74.tail").write_bytes(elf[off + filesz:])

    for name in OVERLAYS:
        data = (ISO_DIR / "BIN" / f"{name}.BIN").read_bytes()
        magic, ovl_id, vram, text, dat, bss = struct.unpack_from("<4sIIIII", data)
        assert magic == b"MWo3", name
        assert len(data) == 0x40 + text + dat, name
        (OUT / f"{name}.head").write_bytes(data[:0x40])
        (OUT / f"{name}.bin").write_bytes(data[0x40:])
        print(f"{name:7} id={ovl_id} vram={vram:#x} text={text:#x} data={dat:#x} bss={bss:#x}")
    print("ok")


if __name__ == "__main__":
    main()
