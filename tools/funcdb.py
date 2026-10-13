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
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from autodecomp import ALABEL, INSN_ADDR  # noqa: E402
from keep_funcs import text_ranges  # noqa: E402
from progress import BINARIES, region  # noqa: E402
from readme_progress import RANGE, tracked_src  # noqa: E402

OUT = ROOT / "build" / "funcdb.tsv"
COLUMNS = ["binary", "func", "addr", "size", "status", "last_result", "blocker",
           "callers", "callees", "strings", "tu"]
MAIN = "SLES_539.74"

# a function in the disassembly, with the optional `nonmatching` marker splat
# writes for functions we do not claim to reproduce yet
GLABEL_BLOCK = re.compile(
    r"^(?:nonmatching \w+, 0x\w+\n\n)?glabel (\w+)\n.*?^endlabel \1\n", re.M | re.S)
# `jal func_X` / `j func_X`. Every instruction line starts with its
# `/* vram */` comment, so the mnemonic is matched after that, not at the line
# start; requiring `func_` keeps jalr and the local `.L` branch targets out.
JUMP = re.compile(r"(?:^|\*/)[ \t]*(?:jal|j)[ \t]+(func_\w+)", re.M)
SRC_CALL = re.compile(r"\bfunc_([0-9A-F]{8})\s*\(")
LO_REF = re.compile(r"%(?:lo|gp_rel)\((D_([0-9A-F]{8}))\)")
SRC_DATA = re.compile(r"\bD_([0-9A-F]{8})\b")
ASCIZ = re.compile(r'/\* \w+ ([0-9A-F]{8}) \*/\s*\.asciz\s+"(.*)"')


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
               "last_result": results.get(entry["func"], "-"),
               "_addr": a, "_body": entry["body"] or ""}
        row["blocker"] = blocker(row, entry)
        rows.append(row)
    return rows


def load_strings(binary):
    """address -> text for every `.asciz` in asm/<bin>/data/*.s."""
    out = {}
    d = ROOT / "asm" / binary / "data"
    for f in sorted(d.glob("*.s")) if d.exists() else []:
        for m in ASCIZ.finditer(f.read_text(errors="replace")):
            out[int(m.group(1), 16)] = m.group(2)
    return out


def in_range(spans, addr):
    return any(s <= addr < e for s, e in spans)


def callees(row, own, main):
    """Function addresses this one jumps to, inside its own binary or the main one.

    Membership is by .text span, not by "is a row": `jal func_0012D4D8` is a
    real call even when that entry point sits inside another function and so
    has no row of its own. An overlay's `jal` into the main executable counts;
    the reverse does not, because every overlay loads at the same address and
    would otherwise claim each other's functions.
    """
    body = row["_body"]
    if row["status"] == "asm":
        targets = {int(n[5:], 16) for n in JUMP.findall(body)}
    else:
        targets = {int(n, 16) for n in SRC_CALL.findall(body)}
    targets.discard(row["_addr"])
    return {t for t in targets
            if in_range(own, t) or (row["binary"] != MAIN and in_range(main, t))}


def link_calls(rows_by_bin):
    """Fill in `callees` and `callers`, the two being inverses of one edge set."""
    spans = {b: text_ranges(b) for b in rows_by_bin}
    main = spans[MAIN]
    edges = {}
    for b, rows in rows_by_bin.items():
        for r in rows:
            targets = callees(r, spans[b], main)
            edges[(b, r["func"])] = targets
            r["callees"] = ",".join(f"func_{t:08X}" for t in sorted(targets)) or "-"
    callers = defaultdict(set)
    for (b, name), targets in edges.items():
        for t in targets:
            if in_range(spans[b], t):
                callers[(b, t)].add(name)
            elif b != MAIN and in_range(main, t):
                callers[(MAIN, t)].add(name)
    for b, rows in rows_by_bin.items():
        for r in rows:
            names = sorted(callers.get((b, r["_addr"]), ()))
            r["callers"] = ",".join(names) or "-"


def shown(text):
    """A string as it goes in the file: 60 characters, no tabs, newlines or bars."""
    return (text[:60].replace("\t", "\\t").replace("\n", "\\n").replace("|", "\\|"))


def refs_of(row):
    """Data addresses the body names: %lo/%gp_rel in asm, any D_ symbol in C."""
    if row["status"] == "asm":
        return {int(a, 16) for _, a in LO_REF.findall(row["_body"])}
    return {int(a, 16) for a in SRC_DATA.findall(row["_body"])}


def add_strings(rows, strs):
    """`strings`, and `tu`: the file a string names, or the one its neighbours name."""
    for r in rows:
        refs = refs_of(r)
        r["_refs"] = [a for a in sorted(refs) if a in strs]
        r["strings"] = " | ".join(shown(strs[a]) for a in r["_refs"]) or "-"
    named = {r["_addr"]: next((strs[a] for a in r["_refs"]
                               if strs[a].endswith((".c", ".cpp"))), "")
             for r in rows}
    have = sorted(a for a, v in named.items() if v)
    for r in rows:
        me = r["_addr"]
        if named[me]:
            r["tu"] = named[me]
            continue
        before = [a for a in have if a < me]
        after = [a for a in have if a > me]
        r["tu"] = (named[before[-1]] + "?") if before and after and \
            named[before[-1]] == named[after[0]] else "-"


def line(row):
    """One tab-separated line, in COLUMNS order; a missing key is `-`."""
    return "\t".join(str(row.get(c, "-")) for c in COLUMNS)


def main():
    tracked = tracked_src()
    rows_by_bin = {b: rows_for(b, tracked) for b in BINARIES}
    strs = {b: load_strings(b) for b in BINARIES}
    link_calls(rows_by_bin)
    for b in BINARIES:
        add_strings(rows_by_bin[b], strs[b])

    out = ["\t".join(COLUMNS)]
    for b in BINARIES:
        rows = rows_by_bin[b]
        out += [line(r) for r in rows]
        print(f"{b} {len(rows)} rows, {sum(r['size'] for r in rows)} bytes")
    named = sum(1 for s in strs[MAIN].values() if s.endswith((".c", ".cpp")))
    print(f"strings: {len(strs[MAIN])} in {MAIN}, {named} of them named .c/.cpp")
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("\n".join(out) + "\n")
    print(f"{OUT.relative_to(ROOT)}: {len(out) - 1} rows")


if __name__ == "__main__":
    main()
