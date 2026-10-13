#!/usr/bin/env python3
"""build/funcdb.tsv: one row per game function, with size, status and blocker.

    tools/funcdb.py            # writes build/funcdb.tsv

A function starts where `progress_stats()` says one does -- a `glabel` in
asm/<bin>/*.s, or the `// range:` line of a src/<bin>/**/*.c* file (tracked or
not, `asmfunc/` included) -- and it counts when tools/progress.py `region()`
calls that address "game" or "text". Size is END - START for a src file and the
next start - START otherwise, so the row count and byte total per binary equal
`readme_progress.progress_stats()` by construction.

Columns come from COLUMNS; a row is a dict, so a new column is one name in
that list and one key in the row.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from autodecomp import ALABEL, INSN_ADDR  # noqa: E402
from progress import BINARIES, region  # noqa: E402
from readme_progress import RANGE, tracked_src  # noqa: E402

OUT = ROOT / "build" / "funcdb.tsv"
COLUMNS = ["binary", "func", "addr", "size", "status", "last_result", "blocker"]

# a function in the disassembly, with the optional `nonmatching` marker splat
# writes for functions we do not claim to reproduce yet
GLABEL_BLOCK = re.compile(
    r"^(?:nonmatching \w+, 0x\w+\n\n)?glabel (\w+)\n.*?^endlabel \1\n", re.M | re.S)


def last_results(binary):
    """name -> the last result recorded for it in build/autodecomp_<bin>.tsv."""
    out = {}
    path = ROOT / "build" / f"autodecomp_{binary}.tsv"
    if path.exists():
        for line in path.read_text(errors="replace").splitlines():
            name, _, why = line.partition("\t")
            if name:
                out[name] = why or "-"
    return out


def starts(binary, tracked):
    """address -> {func, body, kind, end?} for every function start in one binary.

    A src file at the same address replaces the asm label for it, which is what
    `progress_stats()` does, and why the two counts agree.
    """
    entries = {}
    for f in sorted((ROOT / "asm" / binary).glob("*.s")):
        text = f.read_text(errors="replace")
        for m in GLABEL_BLOCK.finditer(text):
            a = INSN_ADDR.search(m.group(0))
            if a:
                entries[int(a.group(1), 16)] = {"func": m.group(1), "body": m.group(0),
                                                "kind": "asm"}
    srcdir = ROOT / "src" / binary
    for f in sorted(srcdir.rglob("*.c*")) if srcdir.exists() else []:
        text = f.read_text(errors="replace")
        m = RANGE.match(text)
        if not m:
            continue
        entries[int(m.group(1), 16)] = {
            "func": f.stem, "body": text, "end": int(m.group(2), 16),
            "kind": ("asmfunc" if "asmfunc" in f.parts else
                     "matched" if f.relative_to(ROOT).as_posix() in tracked else
                     "untracked")}
    return entries


def blocker(row, entry):
    """Why an unmatched function has not matched, most specific first."""
    if row["status"] == "matched":
        return "-"
    body = entry["body"] or ""
    if ALABEL.search(body):
        return "entry-inside"
    if "jtbl_" in body:
        return "jumptable"
    if row["last_result"] == "link":
        return "hilo"
    return "none"


def rows_for(binary, tracked):
    """Row dicts for one binary, in address order."""
    results = last_results(binary)
    entries = starts(binary, tracked)
    addrs = sorted(entries)
    rows = []
    for a, nxt in zip(addrs, addrs[1:] + [None]):
        entry = entries[a]
        end = entry.get("end", nxt)
        if end is None or region(binary, a) not in ("game", "text"):
            continue
        row = {"binary": binary, "func": entry["func"], "addr": f"0x{a:08X}",
               "size": end - a, "status": entry["kind"],
               "last_result": results.get(entry["func"], "-")}
        row["blocker"] = blocker(row, entry)
        rows.append(row)
    return rows


def line(row):
    """One tab-separated line, in COLUMNS order; a missing key is `-`."""
    return "\t".join(str(row.get(c, "-")) for c in COLUMNS)


def main():
    tracked = tracked_src()
    out = ["\t".join(COLUMNS)]
    for b in BINARIES:
        rows = rows_for(b, tracked)
        out += [line(r) for r in rows]
        print(f"{b} {len(rows)} rows, {sum(r['size'] for r in rows)} bytes")
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("\n".join(out) + "\n")
    print(f"{OUT.relative_to(ROOT)}: {len(out) - 1} rows")


if __name__ == "__main__":
    main()
