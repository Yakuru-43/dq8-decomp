#!/usr/bin/env python3
"""Generate splat configs (config/*.yaml).

Text is cut into ~64KB asm chunks at function starts (a stack-frame prologue
right after a `jr $ra` + delay slot and padding) so no branch crosses a file.
Rename/split chunks into real translation units as they get identified.
"""
import hashlib
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
EXTRACT = ROOT / "extract"
CHUNK = 0x10000

# Main executable code regions (vram start, file prefix). Boundaries come from
# function alignment: the Sony SDK libraries were built with GCC (functions on
# 8-byte boundaries, packed) while the game was built with CodeWarrior
# (every function padded to 16 bytes). Exact edges may be off by a function.
MAIN_TEXT_REGIONS = [
    (0x100000, "text"),     # crt0 + runtime
    (0x108398, "sdk"),      # libgraph, libmpeg, libkernl, libcdvd, libpad2, ...
    (0x13B510, "game"),
    (0x252348, "lib"),      # small GCC-built library, unidentified
    (0x252E20, "game"),
    (0x38AE98, "libdbc"),
    (0x38DA10, None),       # end: VU microcode follows
]

def region_prefix(addr):
    """File prefix of the MAIN_TEXT_REGIONS entry containing `addr`."""
    prefix = None
    for start, p in MAIN_TEXT_REGIONS:
        if addr >= start:
            prefix = p
    return prefix


def src_ranges(binary):
    """Decompiled files: src/<binary>/*.c|cpp starting with `// range: 0xSTART 0xEND`.

    Each range starts and ends on function boundaries and replaces that asm.
    """
    out = []
    base = ROOT / "src" / binary
    for p in sorted(base.rglob("*.c*")):
        m = re.match(r"// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", p.read_text())
        if m:
            name = p.relative_to(base).with_suffix("").as_posix()  # e.g. asmfunc/func_X
            out.append((int(m.group(1), 16), int(m.group(2), 16), name, p.suffix[1:]))
    return sorted(out)


RODATA = re.compile(r"^// rodata: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", re.M)


def src_rodata(binary):
    """[(start, end, name)]: the .rodata of src files with a `// rodata: 0xSTART 0xEND` line.

    A switch compiled to a jump table puts the table in the file's .rodata; the
    original table sits in the data segment, so that range of data is cut out
    and the object's .rodata is linked there instead (tools/postsplit.py).
    """
    out = []
    base = ROOT / "src" / binary
    for p in sorted(base.rglob("*.c*")):
        m = RODATA.search(p.read_text())
        if m:
            name = p.relative_to(base).with_suffix("").as_posix()
            out.append((int(m.group(1), 16), int(m.group(2), 16), name))
    return sorted(out)


def splice_rodata(subsegs, binary, vram):
    """Cut each src file's `// rodata:` range out of the data subsegments."""
    for start, end, src in src_rodata(binary):
        start, end = start - vram, end - vram
        before = [c for c in subsegs if c[0] < start]
        after = [c for c in subsegs if c[0] >= end]
        resume = [] if after and after[0][0] == end else [(end, "data", f"data_{vram + end:06X}")]
        subsegs = before + [(start, ".rodata", src)] + resume + after
    return subsegs

COMMON = """\
options:
  platform: ps2
  compiler: MWCCPS2
  base_path: ..
  target_path: extract/{name}.bin
  basename: {name}
  asm_path: asm/{name}
  src_path: src/{name}
  build_path: build
  ld_script_path: linker/{name}.ld
  symbol_addrs_path:
    - config/symbol_addrs.txt
    - config/symbol_addrs_{name}_auto.txt
    - config/symbol_addrs_{name}.txt
  undefined_funcs_auto_path: linker/{name}_undefined_funcs_auto.txt
  undefined_syms_auto_path: linker/{name}_undefined_syms_auto.txt
  ld_bss_is_noload: True
  gp_value: 0x3E7270
  section_order: [".text", ".data", ".rodata", ".bss"]
  string_encoding: SHIFT-JIS
  rodata_string_guesser_level: 2
  data_string_guesser_level: 2
  disasm_unknown: True
  named_regs_for_c_funcs: False
  find_file_boundaries: False
  subalign: 4
  ld_align_segment_vram_end: False
  ld_align_section_vram_end: False
"""


def words(data, start, end):
    return struct.unpack_from(f"<{(end - start) // 4}I", data, start)


def is_func_start(data, off):
    w = struct.unpack_from("<I", data, off)[0]
    if not (w >> 16 == 0x27BD and w & 0x8000):  # addiu $sp, $sp, -N
        return False
    p = off - 4
    while p >= 0 and struct.unpack_from("<I", data, p)[0] == 0:
        p -= 4
    return p >= 4 and struct.unpack_from("<I", data, p - 4)[0] == 0x03E00008


def text_chunks(data, start, end, vram_base, prefix="text"):
    """Yield (offset, name) asm subsegments covering [start, end)."""
    out = [start]
    target = start + CHUNK
    off = target
    while off < end - CHUNK // 4:
        if is_func_start(data, off):
            out.append(off)
            target = off + CHUNK
            off = target
        else:
            off += 4
    return [(o, f"{prefix}_{vram_base + o:06X}") for o in out]


def splice_src(subsegs, binary, vram, prefix_of):
    """Replace asm subsegments with src/<binary> files over their ranges."""
    for start, end, src, lang in src_ranges(binary):
        start, end = start - vram, end - vram
        before = [c for c in subsegs if c[0] < start]
        after = [c for c in subsegs if c[0] >= end]
        resume = [] if after and after[0][0] == end else [(end, "asm", f"{prefix_of(vram + end)}_{vram + end:06X}")]
        subsegs = before + [(start, lang, src)] + resume + after
    return subsegs


def main_yaml():
    name = "SLES_539.74"
    data = (EXTRACT / f"{name}.bin").read_bytes()
    vram = 0x100000
    lines = [f"name: Dragon Quest VIII (PAL)", f"sha1: {hashlib.sha1(data).hexdigest()}",
             COMMON.format(name=name).rstrip(), "segments:"]
    sub = lines.append

    # Separate top-level segments keep the original order: splat would
    # otherwise group every .text before every .data within one segment.
    def seg(seg_name, start, kind, subsegs=None, bss_size=None):
        sub(f"  - name: {seg_name}")
        sub(f"    type: {kind}")
        sub(f"    start: 0x{start:X}")
        sub(f"    vram: 0x{vram + start:X}")
        sub("    align: 4")
        if bss_size is not None:
            sub(f"    bss_size: 0x{bss_size:X}")
        if subsegs:
            sub("    subsegments:")
            for s in subsegs:
                sub(f"      - {s}")

    chunks = []
    for (start, prefix), (end, _) in zip(MAIN_TEXT_REGIONS, MAIN_TEXT_REGIONS[1:]):
        chunks += text_chunks(data, start - vram, end - vram, vram, prefix)
    subsegs = splice_src([(o, "asm", n) for o, n in chunks], name, vram, region_prefix)
    seg("main", 0, "code", [f"[0x{o:X}, {t}, {n}]" for o, t, n in subsegs])
    seg("vu_microcode", 0x28DA10, "bin")
    seg("main2", 0x29D248, "code", ["[0x29D248, asm, text_39D248]"])
    seg("vif_packets", 0x29D548, "bin")
    seg("main3", 0x29D8B8, "code", ["[0x29D8B8, asm, text_39D8B8]"])
    data_subsegs = splice_rodata([(0x29E780, "data", "data_39E780")], name, vram)
    seg("data", 0x29E780, "code", [f"[0x{o:X}, {t}, {n}]" for o, t, n in data_subsegs])
    seg("static_init", 0x2D6100, "code", ["[0x2D6100, asm, static_init]"])
    seg("ctors", 0x2DD3F0, "code", ["[0x2DD3F0, data, ctors]",
                                     f"{{ start: 0x{len(data):X}, type: bss, name: bss }}"],
        bss_size=0x35EC80 - len(data))
    sub(f"  - [0x{len(data):X}]")
    return "\n".join(lines) + "\n"


def overlay_yaml(name):
    head = (EXTRACT / f"{name}.head").read_bytes()
    data = (EXTRACT / f"{name}.bin").read_bytes()
    _, ovl_id, vram, text, dat, bss = struct.unpack_from("<4sIIIII", head)
    vram += len(head)  # the 0x40-byte MWo3 header is loaded at `vram` too; code follows it
    lower = name.lower()
    lines = [f"name: {name}.BIN (overlay {ovl_id})", f"sha1: {hashlib.sha1(data).hexdigest()}",
             COMMON.format(name=name).rstrip(), "segments:",
             f"  - name: {lower}", f"    type: code", f"    start: 0x0", f"    vram: 0x{vram:X}",
             f"    bss_size: 0x{bss:X}", f"    subsegments:"]
    chunks = [(o, "asm", n) for o, n in text_chunks(data, 0, text, vram)]
    for o, t, n in splice_src(chunks, name, vram, lambda addr: "text"):
        lines.append(f"      - [0x{o:X}, {t}, {n}]")
    for o, t, n in splice_rodata([(text, "data", f"data_{vram + text:06X}")], name, vram):
        lines.append(f"      - [0x{o:X}, {t}, {n}]")
    lines.append(f"      - {{ start: 0x{len(data):X}, type: bss, name: bss }}")
    lines.append(f"  - [0x{len(data):X}]")
    return "\n".join(lines) + "\n"


if __name__ == "__main__":
    cfg = ROOT / "config"
    (cfg / "SLES_539.74.yaml").write_text(main_yaml())
    for ovl in ["TITLE", "SHOP", "MENU", "CASINO", "BATTLE"]:
        (cfg / f"{ovl}.yaml").write_text(overlay_yaml(ovl))
        p = cfg / f"symbol_addrs_{ovl}.txt"
        p.exists() or p.write_text("")
    p = cfg / "symbol_addrs_SLES_539.74.txt"
    p.exists() or p.write_text("")
