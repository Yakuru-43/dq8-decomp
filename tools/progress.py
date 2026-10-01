#!/usr/bin/env python3
"""Report decompilation progress: functions and code bytes built from src/.

Counts every function in the binary's code regions: asm labels in asm/<bin>/
plus the `// range:` files in src/<bin>/. Run after `make split`.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from gen_configs import region_prefix  # noqa: E402

BINARIES = ["SLES_539.74", "TITLE", "SHOP", "MENU", "CASINO", "BATTLE"]
FUNC = re.compile(r"^glabel (\w+)\n(?:.*\n)*?\s+/\* \w+ ([0-9A-F]{8}) ", re.M)


def region(binary, addr):
    return (region_prefix(addr) or "other") if binary == "SLES_539.74" else "game"


def main():
    print(f"{'binary':12} {'region':7} {'functions':>17} {'code bytes':>24}")
    for b in BINARIES:
        starts = {}
        for f in (ROOT / "asm" / b).glob("*.s"):
            for m in FUNC.finditer(f.read_text(errors="replace")):
                starts[int(m.group(2), 16)] = "asm"
        kinds = {}
        for f in (ROOT / "src" / b).rglob("*.c*") if (ROOT / "src" / b).exists() else []:
            text = f.read_text()
            m = re.match(r"// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", text)
            if m:
                s, e = int(m.group(1), 16), int(m.group(2), 16)
                starts[s] = "src"
                kinds[s] = (e, "asm" if "asm void" in text else "c")
        addrs = sorted(starts)
        totals = {}
        for a, nxt in zip(addrs, addrs[1:] + [None]):
            end = kinds[a][0] if a in kinds else nxt
            if end is None:
                continue
            r = region(b, a)
            t = totals.setdefault(r, [0, 0, 0, 0, 0])
            t[0] += 1
            t[2] += end - a
            if starts[a] == "src":
                t[1] += 1
                t[3] += end - a
                if kinds[a][1] == "asm":
                    t[4] += 1
        for r, (n, done, size, dsize, asm_fns) in sorted(totals.items()):
            if r not in ("game", "text") and b == "SLES_539.74" and not done:
                note = "  (Sony SDK, GCC-built)" if r in ("sdk", "libdbc", "lib") else ""
            else:
                note = f"  ({asm_fns} as asm functions)" if asm_fns else ""
            print(f"{b:12} {r:7} {done:6}/{n:<6} {100 * done / n:5.1f}%  "
                  f"{dsize:9}/{size:<9} {100 * dsize / size:5.1f}%{note}")


if __name__ == "__main__":
    main()
