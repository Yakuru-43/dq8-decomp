#!/usr/bin/env python3
"""Live progress bar: the README's numbers, plus what the permuter is doing.

    tools/watch.py [--every 10] [--once]

The bars come from `readme_progress.progress_stats()`, so they mean exactly
what the README means: code bytes first, functions second, only files the repo
actually holds, nothing from `src/*/asmfunc/`. Work that is on disk but not
committed gets its own line and is never folded into the totals.

The lower half reads build/permute_batch.done and build/permute_batch.log; it
works whether or not a run is in progress.
"""
import argparse
import datetime
import os
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from progress import BINARIES  # noqa: E402
from readme_progress import progress_stats, tracked_src  # noqa: E402

DONE = ROOT / "build" / "permute_batch.done"
LOG = ROOT / "build" / "permute_batch.log"
PIDFILE = ROOT / "build" / "permute_batch.pid"
WIDTH = 26

START = re.compile(r"^(\d+):(\d+):(\d+) start \(pid (\d+)\): (\d+) functions left, "
                   r"(\d+) already done, .*?([\d.]+)h budget")
STEP = re.compile(r"^(\d+):(\d+):(\d+) \[(\d+)/(\d+)\] .*?\(matches so far: (\d+)\)")


def bar(done, total, width=WIDTH):
    if total <= 0:
        return "░" * width
    filled = max(1, round(width * done / total)) if done else 0
    return "█" * filled + "░" * (width - filled)


def line(label, bn, bt, fn, ft):
    """One row: code bytes first, functions second (same columns as the README)."""
    return (f"{label:13}[{bar(bn, bt)}] {100 * bn / bt if bt else 0:4.1f}% "
            f"{bn / 1024:5.0f}/{bt / 1024:>5.0f} KB  "
            f"[{bar(fn, ft)}] {100 * fn / ft if ft else 0:5.1f}% {fn:5}/{ft:<5}")


def on_disk(binary):
    """Every src file this checkout has, tracked or not, as posix paths."""
    d = ROOT / "src" / binary
    return {f.relative_to(ROOT).as_posix() for f in d.rglob("*.c*")} if d.exists() else set()


def counts():
    """(rows, totals, uncommitted): repo numbers, and what is only on disk.

    The second pass hands progress_stats() a "tracked" set that also contains
    the untracked files, so every untracked C file counts as done; the
    difference is matches written since the last commit. Generated asmfunc
    stays invisible on both sides, which is right: it is asm, not work.
    """
    tracked = tracked_src()
    rows = []
    tf = tt = tb = tbt = 0
    uf = ub = 0
    for b in BINARIES:
        fn, ft, bn, bt = progress_stats(b, tracked)
        dn, _, dbn, _ = progress_stats(b, tracked | on_disk(b))
        tf, tt, tb, tbt = tf + fn, tt + ft, tb + bn, tbt + bt
        uf, ub = uf + (dn - fn), ub + (dbn - bn)
        rows.append(line(b, bn, bt, fn, ft))
    rows.append(line("ALL in repo", tb, tbt, tf, tt))
    return rows, (tf, tt, tb, tbt), (uf, ub)


def alive(pid):
    return pid and (Path("/proc") / str(pid)).is_dir()


def children(pid):
    if not pid:
        return 0
    n = 0
    for entry in os.scandir("/proc"):
        if not entry.name.isdigit():
            continue
        try:
            stat = Path(entry.path, "stat").read_text()
            # comm is in parens and may contain spaces: ppid is the field after them
            if int(stat.rpartition(") ")[2].split()[1]) == pid:
                n += 1
        except OSError:
            pass
    return n


def hms(seconds):
    seconds = int(seconds)
    if seconds < 0:
        return "over"
    h, rem = divmod(seconds, 3600)
    m, s = divmod(rem, 60)
    return f"{h}h{m:02d}" if h else f"{m}m{s:02d}"


def run_info():
    """Everything readable about the permuter: queue, matches, budget, ETA."""
    midnight = datetime.datetime.now().replace(hour=0, minute=0, second=0, microsecond=0)
    now = (datetime.datetime.now() - midnight).total_seconds()
    info = {"done_total": 0, "done_match": 0}
    if DONE.exists():
        for line in DONE.read_text(errors="replace").splitlines():
            parts = line.split("\t")
            if len(parts) == 3 and parts[2]:
                info["done_total"] += 1
                info["done_match"] += parts[2] == "MATCH"
    if PIDFILE.exists():  # authoritative when the log's last start line is stale
        try:
            info["pid"] = int(PIDFILE.read_text())
        except ValueError:
            pass
    if not LOG.exists():
        return info
    lines = LOG.read_text(errors="replace").splitlines()
    start_at = next((i for i in range(len(lines) - 1, -1, -1)
                     if " start (pid " in lines[i]), None)
    if start_at is not None:
        m = START.match(lines[start_at])
        if m:
            h, mi, s, pid, left, before = (int(x) for x in m.groups()[:6])
            hours = float(m.group(7))
            info.setdefault("pid", pid)  # the pidfile, if any, names the latest run
            info.update(left=left, before=before, hours=hours,
                        hours_left=hours * 3600 - (now - (h * 3600 + mi * 60 + s)))
    # only the steps of the run we are describing, so the rate is that run's
    tail = lines[start_at + 1:] if start_at is not None else lines
    steps = [m for m in (STEP.match(ln) for ln in tail) if m]
    if steps:
        last = steps[-1]
        h, mi, s, i, total, matches = (int(x) for x in last.groups())
        info.update(step=i, step_total=total, matches=matches,
                    last=lines[-1].split(" ", 1)[-1] if lines else "")
        first = steps[0]
        t0 = int(first.group(1)) * 3600 + int(first.group(2)) * 60 + int(first.group(3))
        t1 = h * 3600 + mi * 60 + s
        done_now = i - int(first.group(4)) + 1
        if t1 > t0 and done_now > 0:
            info["eta_secs"] = (total - i) / (done_now / (t1 - t0))
            info["eta"] = hms(info["eta_secs"])
    return info


def frame(once):
    rows, (tf, tt, tb, tbt), (uf, ub) = counts()
    at = rows[-1].index("[", rows[-1].index("]") + 1)
    lines = [f"DQ8 (SLES-53974) decompilation     {time.strftime('%H:%M:%S')}", "",
             f"{' ' * 13}{'code bytes':<{at - 13}}functions", *rows]
    if uf or ub:
        size = f"{ub / 1024:.0f} KB" if ub >= 1024 else f"{ub} B"
        lines.append(f"{'':13}uncommitted: {uf} function{'' if uf == 1 else 's'}, {size} "
                     "(matched since the last commit)")

    r = run_info()
    lines.append("")
    pid = r.get("pid")
    if alive(pid):
        load = Path("/proc/loadavg").read_text().split()[0]
        lines.append(f"permuter: RUNNING  pid {pid}  {children(pid)} workers  load {load}")
        i, total = r.get("step", 0), r.get("step_total", 0)
        lines.append(f"{'queue':13}[{bar(i, total)}] {100 * i / total if total else 0:5.1f}% "
                     f"{i:5}/{total:<5} this run   {r.get('before', 0)} done earlier")
        eta = ""
        if r.get("eta"):
            late = (r["eta_secs"] > r["hours_left"]) if "hours_left" in r else False
            eta = f"   ETA {r['eta']}" + " (budget ends first)" if late else ""
        budget = f"   budget left {hms(r['hours_left'])}" if "hours_left" in r else ""
        lines.append(f"{'matches':13}{r.get('matches', 0)} this run   "
                     f"{r.get('done_match', 0)} total{budget}{eta}")
        if r.get("last"):
            lines.append(f"   | {r['last'][:100]}")
    else:
        lines.append(f"permuter: not running   {r.get('done_match', 0)} matches "
                     f"in {r.get('done_total', 0)} screened")
    text = "\n".join(lines)
    sys.stdout.write(("\x1b[H\x1b[J" if not once and sys.stdout.isatty() else "")
                     + text + "\n")
    return text


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--every", type=float, default=10)
    ap.add_argument("--once", action="store_true")
    args = ap.parse_args()
    if args.once:
        frame(True)
        return
    try:
        while True:
            frame(False)
            time.sleep(args.every)
    except KeyboardInterrupt:
        print()


if __name__ == "__main__":
    main()
