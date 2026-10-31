#!/usr/bin/env python3
"""Check one src file the way autodecomp does: compile, link at its address, compare bytes.

    verify.py src/<bin>/func_XXXXXXXX.c|.cpp [...]

The file's `// range: 0xSTART 0xEND` line gives the address and its
`// flags: ...` line (if any) the extra compiler flags; a `// rodata: 0xSTART
0xEND` line says the file's .rodata (a switch's jump table) replaces that range
of the data segment, and it is checked there too.  Prints MATCH or the
reason (align, compile, data, rodata, size, link, mismatch, padding) per file, and on
stderr the line of the compiler's or linker's message that says why; exit status
1 unless every file matches.  This is the only test that counts a function
as matched (CLAUDE.md); tools/try_match.py --show is for looking at diffs.

ALIGN: the range must end on a 16-byte boundary, padding included.  The build
pads every C object to 16 bytes (tools/postsplit.py), so an end short of that
makes gen_configs.py put a few bytes of asm after the padded object and shifts
everything that follows (func_002158B0, 2026-10-31: the main executable's
checksum failed).
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp  # noqa: E402
from autodecomp import VRAM, symbol_script, verify  # noqa: E402


def check(path, syms):
    path = Path(path).resolve()
    binary = path.relative_to(ROOT / "src").parts[0]
    c = path.read_text()
    m = re.search(r"^// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", c, re.M)
    if not m:
        return "no // range: line"
    start, end = int(m.group(1), 16), int(m.group(2), 16)
    if end % 16:
        return "align"
    flags = re.search(r"^// flags: (.*)$", c, re.M)
    if binary not in syms:
        syms[binary] = ROOT / "build" / f"{binary}_all_syms.ld"
        syms[binary].parent.mkdir(exist_ok=True)
        symbol_script(binary, syms[binary])
    base = VRAM.get(binary, 0x45ECC0)
    data = (ROOT / "extract" / f"{binary}.bin").read_bytes()
    ro = re.search(r"^// rodata: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", c, re.M)
    rodata = None
    if ro:
        rs, re_ = int(ro.group(1), 16), int(ro.group(2), 16)
        rodata = (rs, data[rs - base:re_ - base])
    return verify(c, start, end, syms[binary], data[start - base:end - base],
                  tuple(flags.group(1).split()) if flags else (), path.suffix, rodata)


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    syms = {}
    ok = True
    for p in sys.argv[1:]:
        why = check(p, syms)
        print(f"{'MATCH' if why == 'match' else why.upper():9} {p}")
        if why == "align":
            print("          the // range: end must include the padding up to a multiple of 16",
                  file=sys.stderr)
        elif why in ("compile", "link") and autodecomp.last_error:
            print(f"          {autodecomp.last_error}", file=sys.stderr)
        ok &= why == "match"
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
