#!/usr/bin/env python3
"""build/funcdb.tsv: one row per game function, with size, status and blocker.

    tools/funcdb.py            # writes build/funcdb.tsv
    tools/funcdb.py --queue    # and build/queue.tsv, the factory's work queue
    tools/funcdb.py --check    # the two files against the README's own count

A function starts where `progress_stats()` says one does -- a `glabel` in
asm/<bin>/*.s, or the `// range:` line of a src/<bin>/**/*.c* file (tracked or
not, `asmfunc/` included) -- and it counts when tools/progress.py `region()`
calls that address "game" or "text". Size is END - START for a src file and the
next start - START otherwise, so the row count and byte total per binary equal
`readme_progress.progress_stats()` by construction.

Columns come from COLUMNS; a row is a dict, so a new column is one name in
that list and one key in the row.

`--queue` writes the factory's work queue next to it: the same rows minus the
matched ones, with a state and the day it last changed. `write_queue()` reads
the queue back first, so a rebuild never loses a state someone set.

`--check` reads both files back, rebuilds nothing, and fails if any function
is missing from either, or has no blocker class: the Phase 1 gate.
"""
import re
import sys
from collections import Counter, defaultdict
from datetime import date, timedelta
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from autodecomp import ALABEL, INSN_ADDR  # noqa: E402
from keep_funcs import text_ranges  # noqa: E402
from progress import BINARIES, region  # noqa: E402
from readme_progress import RANGE, progress_stats, tracked_src  # noqa: E402

OUT = ROOT / "build" / "funcdb.tsv"
COLUMNS = ["binary", "func", "addr", "size", "status", "last_result", "blocker",
           "callers", "callees", "strings", "tu"]
QUEUE = ROOT / "build" / "queue.tsv"
QCOLUMNS = ["state", "since", "binary", "func", "addr", "size", "blocker", "tu"]
# the states a queue row holds, and the order the factory works the blockers in
STATES = ("todo", "claimed", "matched", "stuck", "needs-claude")
BLOCKERS = ["none", "jumptable", "entry-inside", "hilo"]
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


def read_queue():
    """(binary, func) -> {state, since} for the rows of an existing queue.tsv."""
    out = {}
    if QUEUE.exists():
        for ln in QUEUE.read_text(errors="replace").splitlines()[1:]:
            cols = ln.split("\t")
            if len(cols) >= len(QCOLUMNS):
                out[(cols[2], cols[3])] = {"state": cols[0], "since": cols[1]}
    return out


def stale(since, today):
    """True if a `since` date is more than a day old; an unreadable one is too."""
    try:
        return date.fromisoformat(since) < today - timedelta(days=1)
    except ValueError:
        return True


def queue_row(r, old, today):
    """The queue row for one funcdb row: the state it had, or a fresh `todo`."""
    prev = old.get((r["binary"], r["func"]), {})
    state = prev.get("state", "todo")
    since = prev.get("since", today.isoformat())
    if state == "claimed" and stale(since, today):
        state, since = "todo", today.isoformat()  # a claim nobody finished is free
    return {**r, "state": state, "since": since}


def plain_tu(row):
    """The translation unit without its `?`: a guessed group joins its real one."""
    tu = row["tu"]
    return tu[:-1] if tu.endswith("?") else tu


def queue_sort(row, first):
    """TU group (by where it starts), then unblocked, then smallest."""
    tu = plain_tu(row)
    return (tu == "-", first[tu],
            BLOCKERS.index(row["blocker"]) if row["blocker"] in BLOCKERS else len(BLOCKERS),
            row["size"], row["binary"], row["_addr"])


def write_queue(rows, today):
    """build/queue.tsv: every function the factory still owes, in the order to take it."""
    rows = [queue_row(r, read_queue(), today) for r in rows if r["status"] != "matched"]
    first = {}
    for r in rows:
        t = plain_tu(r)
        first[t] = min(first.get(t, r["_addr"]), r["_addr"])
    rows.sort(key=lambda r: queue_sort(r, first))

    lines = ["\t".join(QCOLUMNS)]
    lines += ["\t".join(str(r[c]) for c in QCOLUMNS) for r in rows]
    tmp = QUEUE.with_name(QUEUE.name + ".tmp")
    tmp.write_text("\n".join(lines) + "\n")  # write-then-rename: never half a queue
    tmp.replace(QUEUE)
    count = Counter(r["state"] for r in rows)
    detail = ", ".join(f"{s} {count[s]}" for s in STATES)
    print(f"queue: {len(rows)} rows ({detail})")


def read_tsv(path):
    """A build/*.tsv back as a list of dicts keyed by its own header."""
    lines = path.read_text(errors="replace").splitlines()
    head = lines[0].split("\t")
    return [dict(zip(head, ln.split("\t"))) for ln in lines[1:] if ln]


def check(db, queue, stats):
    """Every problem with the two files, as lines; empty means both are right."""
    out = []
    owed = set()
    for b in BINARIES:
        rows = [r for r in db if r["binary"] == b]
        f_done, f_total, _, b_total = stats[b]
        size = sum(int(r["size"]) for r in rows)
        if (len(rows), size) != (f_total, b_total):
            out.append(f"{b}: funcdb has {len(rows)} rows / {size} bytes, "
                       f"progress_stats says {f_total} / {b_total}")
        matched = sum(1 for r in rows if r["status"] == "matched")
        if matched != f_done:
            out.append(f"{b}: {matched} matched rows, progress_stats says {f_done} done")
        for r in rows:
            if r["status"] == "matched":
                want = r["blocker"] == "-"
            else:
                owed.add((b, r["func"]))
                want = r["blocker"] in BLOCKERS
            if not want:
                out.append(f"{b} {r['func']}: status {r['status']} with blocker {r['blocker']}")
    have = Counter((r["binary"], r["func"]) for r in queue)
    for k in sorted(owed - set(have)):
        out.append(f"{k[0]} {k[1]}: still owed, no queue row")
    for k in sorted(set(have) - owed):
        out.append(f"{k[0]} {k[1]}: queue row for nothing owed")
    for k, n in sorted(have.items()):
        if n > 1:
            out.append(f"{k[0]} {k[1]}: {n} queue rows, one expected")
    for r in queue:
        if r["state"] not in STATES:
            out.append(f"{r['binary']} {r['func']}: state {r['state']} is not one of {STATES}")
        try:
            date.fromisoformat(r["since"])
        except ValueError:
            out.append(f"{r['binary']} {r['func']}: since {r['since']} is not YYYY-MM-DD")
    return out


def blocker_table(db):
    """Functions and KB still owed, per blocker class, unblocked first."""
    totals = defaultdict(lambda: [0, 0])
    for r in db:
        if r["status"] != "matched":
            totals[r["blocker"]][0] += 1
            totals[r["blocker"]][1] += int(r["size"])
    order = [b for b in BLOCKERS if b in totals] + sorted(set(totals) - set(BLOCKERS))
    lines = [f"{'blocker':<13}{'functions':>11}{'KB':>10}"]
    for b in order + ["total"]:
        if b == "total":
            n, size = sum(v[0] for v in totals.values()), sum(v[1] for v in totals.values())
        else:
            n, size = totals[b]
        lines.append(f"{b:<13}{n:>11}{round(size / 1024):>10}")
    return lines


def check_files():
    """--check: the two build files, against progress_stats and against each other."""
    if not OUT.exists() or not QUEUE.exists():
        print("  build/funcdb.tsv or build/queue.tsv is missing: "
              "run tools/funcdb.py --queue")
        return 1
    stats = {b: progress_stats(b) for b in BINARIES}
    db = read_tsv(OUT)
    problems = check(db, read_tsv(QUEUE), stats)
    for p in problems[:20]:  # the list can run to thousands; twenty say it well enough
        print("  " + p)
    if len(problems) > 20:
        print(f"  ... and {len(problems) - 20} more")
    for ln in blocker_table(db):
        print(ln)
    print(f"check: {'PASS' if not problems else 'FAIL'}")
    return 0 if not problems else 1


def build():
    """Every function of every binary, all columns filled in."""
    tracked = tracked_src()
    rows_by_bin = {b: rows_for(b, tracked) for b in BINARIES}
    strs = {b: load_strings(b) for b in BINARIES}
    link_calls(rows_by_bin)
    for b in BINARIES:
        add_strings(rows_by_bin[b], strs[b])
    named = sum(1 for s in strs[MAIN].values() if s.endswith((".c", ".cpp")))
    print(f"strings: {len(strs[MAIN])} in {MAIN}, {named} of them named .c/.cpp")
    return rows_by_bin


def write_funcdb(rows_by_bin):
    """build/funcdb.tsv, one line per row, binaries in BINARIES order."""
    out = ["\t".join(COLUMNS)]
    for b in BINARIES:
        rows = rows_by_bin[b]
        out += [line(r) for r in rows]
        print(f"{b} {len(rows)} rows, {sum(r['size'] for r in rows)} bytes")
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("\n".join(out) + "\n")
    print(f"{OUT.relative_to(ROOT)}: {len(out) - 1} rows")


def main():
    if "--check" in sys.argv:
        sys.exit(check_files())  # reads the two files back, rebuilds nothing
    rows_by_bin = build()
    write_funcdb(rows_by_bin)
    if "--queue" in sys.argv:
        write_queue([r for b in BINARIES for r in rows_by_bin[b]], date.today())


if __name__ == "__main__":
    main()
