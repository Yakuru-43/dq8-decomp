#!/usr/bin/env python3
"""Refresh the progress bars in README.md (between the progress markers).

Counts only what a fresh clone of the repo actually builds from C: files
`git ls-files` knows about, and nothing under `src/*/asmfunc/` (generated
verbatim asm, git-ignored). Work that is on disk but not in the repo still
claims its `// range:` -- so the sizes of everything else stay right -- but
counts as not done.

    tools/readme_progress.py

`progress_stats(binary)` is the same count for other tools (tools/watch.py).
"""
import datetime
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from progress import BINARIES, FUNC, region  # noqa: E402

START = "<!-- progress:start -->"
END = "<!-- progress:end -->"
WIDTH = 20
RANGE = re.compile(r"// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)")


def tracked_src():
    """The src paths a fresh clone would have, as one set of posix strings."""
    r = subprocess.run(["git", "ls-files", "src"], cwd=ROOT, capture_output=True,
                       text=True, check=True)
    return set(r.stdout.split())


def progress_stats(binary, tracked=None):
    """(funcs_done, funcs_total, bytes_done, bytes_total) for the game/text regions.

    A src file counts as done only when it is tracked and no path component is
    `asmfunc`. Pass `tracked_src()` in when calling this for several binaries.
    """
    if tracked is None:
        tracked = tracked_src()
    starts = {}  # address -> "asm", "done" (in the repo) or "claim" (only on disk)
    ends = {}
    for f in (ROOT / "asm" / binary).glob("*.s"):
        for m in FUNC.finditer(f.read_text(errors="replace")):
            starts[int(m.group(2), 16)] = "asm"
    srcdir = ROOT / "src" / binary
    for f in srcdir.rglob("*.c*") if srcdir.exists() else []:
        m = RANGE.match(f.read_text(errors="replace"))
        if not m:
            continue
        s, e = int(m.group(1), 16), int(m.group(2), 16)
        in_repo = f.relative_to(ROOT).as_posix() in tracked and "asmfunc" not in f.parts
        starts[s] = "done" if in_repo else "claim"
        ends[s] = e
    fn = ft = bn = bt = 0
    addrs = sorted(starts)
    for a, nxt in zip(addrs, addrs[1:] + [None]):
        end = ends.get(a, nxt)
        if end is None:
            continue
        if region(binary, a) not in ("game", "text"):
            continue
        ft += 1
        bt += end - a
        if starts[a] == "done":
            fn += 1
            bn += end - a
    return fn, ft, bn, bt


def bar(done, total):
    if total == 0:
        return "░" * WIDTH
    filled = max(1, round(WIDTH * done / total)) if done else 0
    return "█" * filled + "░" * (WIDTH - filled)


def rows():
    """(lines, (funcs_done, funcs_total, bytes_done, bytes_total)).

    One line per binary plus the total; code bytes first, functions second.
    """
    tracked = tracked_src()
    out = []
    tf = tt = tb = tbt = 0
    for b in BINARIES:
        fn, ft, bn, bt = progress_stats(b, tracked)
        tf, tt, tb, tbt = tf + fn, tt + ft, tb + bn, tbt + bt
        label = b if b == "SLES_539.74" else f"{b} (overlay)"
        out.append(
            f"{label:17}[{bar(bn, bt)}] {100 * bn / bt if bt else 0:4.1f}% "
            f"{bn / 1024:6.0f}/{bt / 1024:>5.0f} KB   "
            f"[{bar(fn, ft)}] {100 * fn / ft if ft else 0:5.1f}% {fn:5}/{ft:<5}")
    out.append(f"{'ALL game code':17}[{bar(tb, tbt)}] {100 * tb / tbt:4.1f}% "
               f"{tb / 1024:6.0f}/{tbt / 1024:>5.0f} KB   "
               f"[{bar(tf, tt)}] {100 * tf / tt:5.1f}% {tf:5}/{tt:<5}")
    return out, (tf, tt, tb, tbt)


def main():
    readme = ROOT / "README.md"
    text = readme.read_text()
    if START not in text or END not in text:
        sys.exit(f"markers {START!r}/{END!r} not found in README.md")

    body, (tf, tt, tb, tbt) = rows()
    # align the header words with the two bars rather than counting columns
    at = body[-1].index("[", body[-1].index("]") + 1)
    lines = ["```", f"{' ' * 17}{'code bytes':<{at - 17}}functions", *body, "```"]
    lines.append(f"_(refreshed {datetime.date.today().isoformat()} by `tools/readme_progress.py`; "
                 "only files in the repo count -- `src/*/asmfunc/` is generated asm and "
                 "uncommitted work is not progress; run `tools/progress.py` for the per-region table)_")

    head, rest = text.split(START, 1)
    _, tail = rest.split(END, 1)
    readme.write_text(head + START + "\n" + "\n".join(lines) + "\n" + END + tail)
    print(f"updated {readme}: {tb / 1024:.0f}/{tbt / 1024:.0f} KB "
          f"({100 * tb / tbt:.1f}% of code bytes), {tf}/{tt} functions "
          f"({100 * tf / tt:.1f}%)")


if __name__ == "__main__":
    main()
