#!/usr/bin/env python3
"""Live progress bar: functions decompiled, and what the permuter is doing.

    tools/watch.py [--every 10] [--once]

The top bar counts what is in src/ right now, so it moves while
permute_batch.py runs (a match is written straight into src/<bin>/). Asm labels
a new src range swallowed are left out of the total, so the percentage stays
honest before `make split` reconciles the asm side.

The lower half reads build/permute_batch.done and build/permute_batch.log; it
works whether or not a run is in progress.
"""
import argparse
import bisect
import datetime
import os
import re
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from progress import BINARIES, FUNC, region  # noqa: E402

RANGE = re.compile(r"// range: (0x[0-9A-Fa-f]+) (0x[0-9A-Fa-f]+)")
DONE = ROOT / "build" / "permute_batch.done"
LOG = ROOT / "build" / "permute_batch.log"
PIDFILE = ROOT / "build" / "permute_batch.pid"
WIDTH = 28

START = re.compile(r"^(\d+):(\d+):(\d+) start \(pid (\d+)\): (\d+) functions left, "
                   r"(\d+) already done, .*?([\d.]+)h budget")
STEP = re.compile(r"^(\d+):(\d+):(\d+) \[(\d+)/(\d+)\] .*?\(matches so far: (\d+)\)")


def bar(done, total, width=WIDTH):
    if total <= 0:
        return "░" * width
    filled = max(1, round(width * done / total)) if done else 0
    return "█" * filled + "░" * (width - filled)


def asm_starts(binary):
    """(glabel addresses, newest .s mtime) in asm/<bin>/.

    `make split` rewrites the .s files, so their newest mtime is when asm was
    last reconciled with src/ -- a src file newer than that is a match the
    build has not folded in yet. A full scan costs ~0.3 s, so nothing is cached.
    """
    out, newest = [], 0.0
    for f in (ROOT / "asm" / binary).glob("*.s"):
        out += [int(m.group(2), 16) for m in FUNC.finditer(f.read_text(errors="replace"))]
        newest = max(newest, f.stat().st_mtime)
    return out, newest


def src_ranges(binary):
    """(start, end, mtime) for every `// range:` file in src/<bin>/."""
    out = []
    d = ROOT / "src" / binary
    if d.exists():
        for f in d.rglob("*.c*"):
            with f.open(errors="replace") as fh:
                m = RANGE.match(fh.read(200))
            if m:
                out.append((int(m.group(1), 16), int(m.group(2), 16), f.stat().st_mtime))
    return sorted(out)


def tally(binary):
    """(funcs_done, funcs_total, bytes_done, bytes_total, waiting_for_split).

    `waiting_for_split` counts src files newer than the newest .s: matches the
    permuter wrote since `make split` last reconciled the two trees.
    """
    srcs = src_ranges(binary)
    asm_list, newest_asm = asm_starts(binary)
    src_at = {s: e for s, e, _ in srcs}
    begins = [s for s, _, _ in srcs]
    ends = [e for _, e, _ in srcs]
    waiting = sum(1 for _, _, mt in srcs if mt > newest_asm)
    # a src range covers the asm labels inside it; they are not extra functions
    keep = []
    for a in asm_list:
        i = bisect.bisect_right(begins, a) - 1
        if not (i >= 0 and begins[i] < a < ends[i]):
            keep.append(a)
    starts = sorted(set(keep) | set(begins))
    fn = ft = bn = bt = 0
    for a, nxt in zip(starts, starts[1:] + [None]):
        end = src_at.get(a, nxt)
        if end is None or end <= a or region(binary, a) not in ("game", "text"):
            continue
        ft += 1
        bt += end - a
        if a in src_at:
            fn += 1
            bn += end - a
    return fn, ft, bn, bt, waiting


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
            rate = done_now / (t1 - t0)
            info["eta_secs"] = (total - i) / rate
            info["eta"] = hms(info["eta_secs"])
    return info


def frame(once):
    lines = []
    now = time.strftime("%H:%M:%S")
    lines.append(f"DQ8 (SLES-53974) decompilation     {now}")
    lines.append("")
    tf = tt = tb = tbt = tw = 0
    for b in BINARIES:
        fn, ft, bn, bt, wait = tally(b)
        tf, tt, tb, tbt, tw = tf + fn, tt + ft, tb + bn, tbt + bt, tw + wait
        lines.append(f"{b:13}[{bar(fn, ft)}] {100 * fn / ft if ft else 0:5.1f}% "
                     f"{fn:5}/{ft:<5}")
    lines.append("")
    lines.append(f"{'functions':13}[{bar(tf, tt)}] {100 * tf / tt:5.1f}% {tf:5}/{tt:<5}"
                 f"   {'code':4} {tb / 1024:5.0f}/{tbt / 1024:.0f} KB")
    if tw:
        lines.append(f"{'':13}{tw} still to fold in: `make split && make -j`")

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
    text = "\n".join(ln for ln in lines if ln is not None)
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
