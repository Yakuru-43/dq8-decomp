#!/usr/bin/env python3
"""Check one src file the way autodecomp does: compile, link at its address, compare bytes.

    verify.py src/<bin>/func_XXXXXXXX.c [...]

The file's `// range: 0xSTART 0xEND` line gives the address and its
`// flags: ...` line (if any) the extra compiler flags.  Prints MATCH or the
reason (compile, data, size, link, mismatch, padding) per file; exit status
1 unless every file matches.  This is the only test that counts a function
as matched (CLAUDE.md); tools/try_match.py --show is for looking at diffs.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from autodecomp import VRAM, symbol_script, verify  # noqa: E402


def check(path, syms):
    path = Path(path).resolve()
    binary = path.relative_to(ROOT / "src").parts[0]
    c = path.read_text()
    m = re.search(r"^// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", c, re.M)
    if not m:
        return "no // range: line"
    start, end = int(m.group(1), 16), int(m.group(2), 16)
    flags = re.search(r"^// flags: (.*)$", c, re.M)
    if binary not in syms:
        syms[binary] = ROOT / "build" / f"{binary}_all_syms.ld"
        syms[binary].parent.mkdir(exist_ok=True)
        symbol_script(binary, syms[binary])
    base = VRAM.get(binary, 0x45EC80)
    data = (ROOT / "extract" / f"{binary}.bin").read_bytes()
    return verify(c, start, end, syms[binary], data[start - base:end - base],
                  tuple(flags.group(1).split()) if flags else ())


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    syms = {}
    ok = True
    for p in sys.argv[1:]:
        why = check(p, syms)
        print(f"{'MATCH' if why == 'match' else why.upper():9} {p}")
        ok &= why == "match"
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
