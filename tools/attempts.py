#!/usr/bin/env python3
"""Attempts log: what has been tried on each function, so nobody tries it again.

notes/attempts.jsonl holds one JSON object per attempt:
  {"func", "time", "who" (qwen/opus/loop/tool), "hypothesis", "result", "diff", "file"}
`diff` is try_match's count of differing words (null when unknown), `file` the
draft the attempt left behind, if any.

    attempts.py log FUNC --who qwen --hypothesis "..." --result mismatch [--diff 4] [--file path]
                       append a record; warns when a similar hypothesis is
                       already recorded for the function
    attempts.py show FUNC [--records-only]
                       the function's records, then the closest drafts on disk
    attempts.py seed   fill the log from notes/needs-claude/*.md and the prompt
                       loop's ~/qwen-runs/loop-results.tsv (records already
                       there are not added twice)

Read `show` before the first try on a function; log every idea that failed.
"""
import argparse
import difflib
import json
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LOG = ROOT / "notes" / "attempts.jsonl"
NOTES = ROOT / "notes" / "needs-claude"
LOOP_RESULTS = Path.home() / "qwen-runs" / "loop-results.tsv"
LOOP_DRAFTS = Path.home() / "Code/DQ8_w7/scratch/loop"
WHO = ("qwen", "opus", "loop", "tool")
SCORE = re.compile(r"score=(\d+)|(\d+) words? differ")


def records(func=None):
    if not LOG.exists():
        return []
    out = [json.loads(line) for line in LOG.read_text().splitlines() if line.strip()]
    return [r for r in out if func is None or r["func"] == func]


def similar(a, b):
    """Two hypotheses that say the same thing in other words."""
    wa, wb = set(re.findall(r"\w+", a.lower())), set(re.findall(r"\w+", b.lower()))
    jaccard = len(wa & wb) / len(wa | wb) if wa | wb else 1
    return jaccard >= 0.6 or difflib.SequenceMatcher(None, a.lower(), b.lower()).ratio() >= 0.8


def append(recs):
    LOG.parent.mkdir(parents=True, exist_ok=True)
    with LOG.open("a") as f:
        for r in recs:
            f.write(json.dumps(r, ensure_ascii=False) + "\n")


def record(func, who, hypothesis, result, diff=None, file=None, when=None):
    return {"func": func, "time": when or time.strftime("%Y-%m-%dT%H:%M:%S"), "who": who,
            "hypothesis": hypothesis, "result": result, "diff": diff, "file": file}


def drafts(func):
    """Sources of the function lying around, closest kind first."""
    found = list((ROOT / "src").glob(f"*/{func}.c*"))
    found += sorted(NOTES.glob(f"{func}_best.c*"))
    if (LOOP_DRAFTS / f"{func}.c").exists():
        found.append(LOOP_DRAFTS / f"{func}.c")
    for wt in [ROOT] + sorted(ROOT.parent.glob("DQ8_w*")):
        found += sorted((wt / "build/repair").glob(f"*/{func}.c*"))
    seen, out = set(), []
    for p in found:
        if p.resolve() not in seen:
            seen.add(p.resolve())
            out.append(p)
    return out


def cmd_log(a):
    old = [r for r in records(a.func) if similar(r["hypothesis"], a.hypothesis)]
    for r in old:
        print(f"warning: {a.func} already has a similar attempt ({r['time'][:10]}, {r['who']}, "
              f"{r['result']}): {r['hypothesis']}", file=sys.stderr)
    append([record(a.func, a.who, a.hypothesis, a.result, a.diff, a.file)])


def cmd_show(a):
    recs = records(a.func)
    for r in recs:
        diff = f", {r['diff']} words differ" if r.get("diff") is not None else ""
        file = f"  [{r['file']}]" if r.get("file") else ""
        print(f"{r['time'][:16]} {r['who']:5} {r['result']}{diff}: {r['hypothesis']}{file}")
    if a.records_only:
        return
    if not recs:
        print(f"no attempts recorded for {a.func}")
    ds = drafts(a.func)
    if ds:
        print("drafts on disk:")
        for p in ds:
            print(f"  {p}")


def commit_times():
    """{path: time of the first commit that added it} for the needs-claude notes."""
    r = subprocess.run(["git", "log", "--diff-filter=A", "--format=@%cI", "--name-only", "--",
                        NOTES.relative_to(ROOT).as_posix()], cwd=ROOT, capture_output=True, text=True)
    out, when = {}, None
    for line in r.stdout.splitlines():
        if line.startswith("@"):
            when = line[1:20]
        elif line.strip():
            out[line.strip()] = when       # newest first: the last one seen is the oldest
    return out


def note_records(path, added):
    """Records for one needs-claude note: one per bullet of its 'tried' list, or one for the note."""
    func = path.stem
    text = path.read_text(errors="replace")
    when = added.get(path.relative_to(ROOT).as_posix()) or \
        time.strftime("%Y-%m-%dT%H:%M:%S", time.localtime(path.stat().st_mtime))
    m = SCORE.search(text)
    diff = int(m.group(1) or m.group(2)) if m else None
    best = sorted(NOTES.glob(f"{func}_best.c*"))
    file = best[0].relative_to(ROOT).as_posix() if best else path.relative_to(ROOT).as_posix()
    who = "opus" if re.search(r"\bopus\b", text, re.I) else "qwen"
    tried = re.search(r"^#+ .*\b[Tt]ried\b.*\n((?:.*\n)*?)(?=^#|\Z)", text, re.M)
    bullets = []
    if tried:
        for b in re.split(r"\n(?=\s*(?:[-*]|\d+\.)\s)", tried.group(1)):
            b = " ".join(b.split("\n\n")[0].split())       # a paragraph after the list is not a bullet
            b = re.sub(r"^(?:[-*]|\d+\.)\s+", "", b)
            if b and not b.lower().startswith("not tried"):
                bullets.append(b[:400])
    if not bullets:
        title = next((l.lstrip("# ").strip() for l in text.splitlines() if l.startswith("#")), func)
        bullets = [f"needs-claude note: {title}"[:400]]
    return [record(func, who, b, "fail", diff, file, when) for b in bullets]


def loop_records():
    out = []
    if not LOOP_RESULTS.exists():
        return out
    for line in LOOP_RESULTS.read_text().splitlines():
        p = line.split("\t")
        if len(p) < 5 or p[3] == "match":
            continue
        when, func, size, result, tries = p[:5]
        draft = LOOP_DRAFTS / f"{func}.c"
        out.append(record(func, "loop", f"prompt loop: qwen from the m2c draft, {tries} tries",
                          result, None, str(draft) if draft.exists() else None, when))
    return out


def cmd_seed(a):
    have = {(r["func"], r["who"], r["hypothesis"], r["time"]) for r in records()}
    new = []
    added = commit_times()
    for path in sorted(NOTES.glob("func_*.md")):
        new += note_records(path, added)
    new += loop_records()
    new = [r for r in new if (r["func"], r["who"], r["hypothesis"], r["time"]) not in have]
    append(new)
    print(f"{len(new)} records added ({len({r['func'] for r in new})} functions); "
          f"{len(records())} in {LOG.relative_to(ROOT)}")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)
    lg = sub.add_parser("log")
    lg.add_argument("func")
    lg.add_argument("--who", choices=WHO, required=True)
    lg.add_argument("--hypothesis", required=True)
    lg.add_argument("--result", required=True)
    lg.add_argument("--diff", type=int)
    lg.add_argument("--file")
    sh = sub.add_parser("show")
    sh.add_argument("func")
    sh.add_argument("--records-only", action="store_true")
    sub.add_parser("seed")
    a = p.parse_args()
    {"log": cmd_log, "show": cmd_show, "seed": cmd_seed}[a.cmd](a)


if __name__ == "__main__":
    main()
