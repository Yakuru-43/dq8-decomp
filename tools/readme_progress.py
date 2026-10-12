#!/usr/bin/env python3
"""Refresh the progress bars in README.md (between the progress markers).

Same numbers as tools/progress.py (run after `make split`), rendered as
ASCII bars: one line per binary's game code, plus a total.

    tools/readme_progress.py
"""
import datetime
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from progress import BINARIES, FUNC, region  # noqa: E402

START = "<!-- progress:start -->"
END = "<!-- progress:end -->"
WIDTH = 20


def stats(binary):
    """(funcs_done, funcs_total, bytes_done, bytes_total) for the game/text regions."""
    starts = {}
    for f in (ROOT / "asm" / binary).glob("*.s"):
        for m in FUNC.finditer(f.read_text(errors="replace")):
            starts[int(m.group(2), 16)] = "asm"
    kinds = {}
    srcdir = ROOT / "src" / binary
    for f in srcdir.rglob("*.c*") if srcdir.exists() else []:
        text = f.read_text()
        m = re.match(r"// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)", text)
        if m:
            s, e = int(m.group(1), 16), int(m.group(2), 16)
            starts[s] = "src"
            kinds[s] = (e, "asm" if "asm void" in text else "c")
    fn = ft = bn = bt = 0
    addrs = sorted(starts)
    for a, nxt in zip(addrs, addrs[1:] + [None]):
        end = kinds[a][0] if a in kinds else nxt
        if end is None:
            continue
        if region(binary, a) not in ("game", "text"):
            continue
        ft += 1
        bt += end - a
        if starts[a] == "src":
            fn += 1
            bn += end - a
    return fn, ft, bn, bt


def bar(done, total):
    if total == 0:
        return "░" * WIDTH
    filled = max(1, round(WIDTH * done / total)) if done else 0
    return "█" * filled + "░" * (WIDTH - filled)


def main():
    readme = ROOT / "README.md"
    text = readme.read_text()
    if START not in text or END not in text:
        sys.exit(f"markers {START!r}/{END!r} not found in README.md")

    lines = ["```",
             "                 functions                              code bytes"]
    tf = tt = tb = tbt = 0
    for b in BINARIES:
        fn, ft, bn, bt = stats(b)
        tf, tt, tb, tbt = tf + fn, tt + ft, tb + bn, tbt + bt
        label = b if b == "SLES_539.74" else f"{b} (overlay)"
        lines.append(
            f"{label:17}[{bar(fn, ft)}] {100 * fn / ft if ft else 0:5.1f}% "
            f"{fn:5}/{ft:<5}      [{bar(bn, bt)}] {100 * bn / bt if bt else 0:4.1f}% "
            f"{bn / 1024:6.0f}/{bt / 1024:.0f} KB")
    lines.append(f"{'ALL game code':17}[{bar(tf, tt)}] {100 * tf / tt:5.1f}% "
                 f"{tf:5}/{tt:<5}      [{bar(tb, tbt)}] {100 * tb / tbt:4.1f}% "
                 f"{tb / 1024:6.0f}/{tbt / 1024:.0f} KB")
    lines.append("```")
    lines.append(f"_(refreshed {datetime.date.today().isoformat()} by `tools/readme_progress.py`; "
                 "run `tools/progress.py` for the per-region table)_")

    head, rest = text.split(START, 1)
    _, tail = rest.split(END, 1)
    readme.write_text(head + START + "\n" + "\n".join(lines) + "\n" + END + tail)
    print(f"updated {readme}: {tf}/{tt} functions, {tb / 1024:.0f}/{tbt / 1024:.0f} KB")


if __name__ == "__main__":
    main()
