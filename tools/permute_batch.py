#!/usr/bin/env python3
"""Run decomp-permuter over functions whose m2c draft compiles but mismatches.

    permute_batch.py [--hours 10] [--per-func 180] [--parallel 7] [-j 2]

Candidates come from build/autodecomp_<bin>.tsv (latest result per function:
mismatch/size/repaired), smallest first, for every binary. A `repaired`
function is permuted from build/repair/<bin>/<func>.c, the draft that
tools/repair.py made compile, instead of from a fresh m2c draft. Each function gets
--per-func seconds; a score-0 result is re-verified exactly like autodecomp
(linked at its real address, byte-compared) before src/<bin>/<func>.c is written.
A draft whose own score is above --max-base is dropped after a few seconds
(`hopeless=N` in the done file): reordering cannot close a draft that is that
far from the target, and it would otherwise eat the whole budget.
Resumable: finished functions are recorded in build/permute_batch.done; just
run the same command again after a reboot. Functions interrupted by shutdown
(SIGTERM/SIGINT/SIGHUP) are not recorded and get redone.
Stop early by creating build/permute_batch.stop or `kill $(cat build/permute_batch.pid)`.
Log: build/permute_batch.log.
Afterwards: `make split && make -j` to fold matches into the build.
"""
import argparse
import os
import re
import shutil
import signal
import subprocess
import sys
import time
import threading
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp as a  # noqa: E402

BINARIES = ["SLES_539.74", "TITLE", "SHOP", "MENU", "CASINO", "BATTLE"]
PERMUTER = ROOT / ".toolchain" / "permuter" / "permuter.py"
WORK = ROOT / "build" / "permute"
DONE = ROOT / "build" / "permute_batch.done"
STOP = ROOT / "build" / "permute_batch.stop"
LOG = ROOT / "build" / "permute_batch.log"
PIDFILE = ROOT / "build" / "permute_batch.pid"

STOPPING = threading.Event()
CHILDREN = set()
CHILDREN_LOCK = threading.Lock()


def on_signal(signum, _frame):
    """Shutdown/logout: stop children now, record nothing for in-flight functions."""
    STOPPING.set()
    with CHILDREN_LOCK:
        for p in list(CHILDREN):
            try:
                os.killpg(p.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass


def record_done(binary, func, result):
    with open(DONE, "a") as f:
        f.write(f"{binary}\t{func}\t{result}\n")
        f.flush()
        os.fsync(f.fileno())


def load_done():
    """(binary, func) pairs already finished; ignores a torn last line from a power cut."""
    if not DONE.exists():
        return set()
    out = set()
    for line in DONE.read_text(errors="replace").splitlines():
        parts = line.split("\t")
        if len(parts) == 3 and parts[2]:
            out.add((parts[0], parts[1]))
    return out


def log(msg):
    line = f"{time.strftime('%H:%M:%S')} {msg}"
    print(line, flush=True)
    with open(LOG, "a") as f:
        f.write(line + "\n")


def candidates(binary):
    tsv = ROOT / "build" / f"autodecomp_{binary}.tsv"
    if not tsv.exists():
        return []
    latest = {}
    for line in tsv.read_text().splitlines():
        name, _, why = line.partition("\t")
        latest[name] = why
    want = {n for n, w in latest.items() if w in ("mismatch", "size", "repaired")}
    funcs = [f for f in a.functions(binary) if f[0] in want]
    return sorted(funcs, key=lambda f: f[2] - f[1])


def base_source(binary, func, asm):
    """(source, note): what to permute, and how to describe it in src/."""
    saved = ROOT / "build" / "repair" / binary / f"{func}.c"
    if saved.exists():  # m2c draft whose types tools/repair.py fixed for CodeWarrior
        return saved.read_text(), "m2c draft with casts added"
    draft = next(a.candidates(func, asm), None)
    return (draft[1], "m2c draft") if draft else (None, None)


def setup(binary, func, asm):
    source, _ = base_source(binary, func, asm)
    if not source:
        return None
    d = WORK / binary / func
    shutil.rmtree(d, ignore_errors=True)
    d.mkdir(parents=True)
    common = (ROOT / "include/common.h").read_text()
    # pycparser can't parse __attribute__; keep it out of the permuted source and
    # restore it in compile.sh with a marker macro
    c = source.replace('#include "common.h"', common)
    c = c.replace('__attribute__((section(".data")))', "DATA_SECTION")
    c = "#ifndef DATA_SECTION\n#define DATA_SECTION\n#endif\n" + c
    (d / "base.c").write_text(c)
    (d / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + asm)
    r = subprocess.run([a.BIN / "mips64-linux-gnu-as", "-EL", "-march=r5900", "-mabi=o64", "-G0",
                        "-no-pad-sections", "-I", ROOT / "include", d / "target.s", "-o", d / "target.o"],
                       capture_output=True)
    if r.returncode:
        return None
    (d / "compile.sh").write_text(
        "#!/bin/sh\n"
        f'exec "{a.TC / "wibo"}" "{a.MWCC}" -c {" ".join(a.CFLAGS)} '
        "'-DDATA_SECTION=__attribute__((section(\".data\")))' \"$1\" -o \"$3\"\n")
    (d / "compile.sh").chmod(0o755)
    (d / "settings.toml").write_text(
        f'func_name = "{func}"\ncompiler_type = "mwcc"\n'
        f'objdump_command = "{a.BIN / "mips64-linux-gnu-objdump"} -drz -m mips:5900"\n')
    return d


def finalize(binary, func, start, end, d, syms, orig):
    """Verify score-0 outputs; write the first exact one to src/."""
    for out in sorted(d.glob("output-0-*")):
        src = (out / "source.c").read_text()
        src = src.replace("DATA_SECTION", '__attribute__((section(".data")))')
        src = re.sub(r"^#ifndef __attribute__.*?#endif\n", "", src, flags=re.S | re.M)
        if a.verify(src, start, end, syms, orig) == "match":
            dest = ROOT / "src" / binary / f"{func}.c"
            dest.parent.mkdir(parents=True, exist_ok=True)
            saved = (ROOT / "build" / "repair" / binary / f"{func}.c").exists()
            dest.write_text(f"// range: 0x{start:X} 0x{end:X}\n// auto: m2c draft"
                            f"{' with casts added' if saved else ''} + decomp-permuter, "
                            "verified byte-exact\n" + src)
            return True
    return False


BASE_SCORE = re.compile(r"base score = (\d+)")


def watch(p, out_path, budget, max_base):
    """Follow the permuter's log until it starts permuting.

    Its first line of real work is the score of the unpermuted draft. A draft
    that is already far from the target cannot be closed by reordering, and
    spending the whole budget on it is the main waste here, so it gets killed
    and recorded instead.
    """
    start = time.time()
    while True:
        text = ""
        try:
            text = Path(out_path).read_text(errors="replace")
        except OSError:
            pass
        m = BASE_SCORE.search(text)
        if m and int(m.group(1)) > max_base:
            return "hopeless", int(m.group(1))
        if p.poll() is not None:
            return "exit", None
        if STOPPING.is_set() or time.time() - start > budget:
            return "wait", None
        time.sleep(3)


def run_one(job, per_func, jobs, deadline, max_base):
    binary, (func, start, end, asm, _), syms, orig = job
    if STOPPING.is_set() or STOP.exists() or time.time() > deadline:
        return func, "skipped"
    d = setup(binary, func, asm)
    if not d:
        record_done(binary, func, "setup-failed")
        return func, "setup-failed"
    budget = int(min(per_func, deadline - time.time()))
    if budget < 30:
        return func, "skipped"
    out = open(d / "permuter.out", "w")
    p = subprocess.Popen([sys.executable, PERMUTER, d, "--stop-on-zero", "-j", str(jobs)],
                         stdout=out, stderr=subprocess.STDOUT, start_new_session=True)
    with CHILDREN_LOCK:
        CHILDREN.add(p)
    try:
        status, score = watch(p, d / "permuter.out", budget, max_base)
        if status in ("hopeless", "wait"):
            os.killpg(p.pid, signal.SIGKILL)
            p.wait()
    finally:
        with CHILDREN_LOCK:
            CHILDREN.discard(p)
        out.close()
    if status == "hopeless" and not STOPPING.is_set():
        record_done(binary, func, f"hopeless={score}")
        shutil.rmtree(d, ignore_errors=True)
        return func, f"hopeless({score})"
    if STOPPING.is_set():
        # interrupted (shutdown): don't record, so a resumed run redoes it
        shutil.rmtree(d, ignore_errors=True)
        return func, "interrupted"
    text = (d / "permuter.out").read_text(errors="replace")
    if "Traceback" in text or "base score" not in text:
        result = "permuter-error"
    elif finalize(binary, func, start, end, d, syms, orig):
        result = "MATCH"
    else:
        scores = [int(o.name.split("-")[1]) for o in d.glob("output-*")]
        result = f"best={min(scores)}" if scores else "no-improvement"
    if result != "MATCH":
        shutil.rmtree(d, ignore_errors=True)  # keep only matches' work dirs
    record_done(binary, func, result)
    return func, result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--hours", type=float, default=10)
    ap.add_argument("--per-func", type=int, default=180)
    ap.add_argument("--parallel", type=int, default=7)
    ap.add_argument("-j", type=int, default=2)
    ap.add_argument("--max-base", type=int, default=400,
                    help="give up on drafts whose unpermuted score is above this")
    args = ap.parse_args()

    if PIDFILE.exists():
        try:
            old = int(PIDFILE.read_text())
            os.kill(old, 0)
            sys.exit(f"already running as pid {old}")
        except (ValueError, ProcessLookupError, PermissionError):
            pass  # stale pid file from a shutdown
    PIDFILE.write_text(str(os.getpid()))
    for sig in (signal.SIGTERM, signal.SIGINT, signal.SIGHUP):
        signal.signal(sig, on_signal)

    deadline = time.time() + args.hours * 3600
    STOP.unlink(missing_ok=True)
    done = load_done()

    jobs = []
    for b in BINARIES:
        base = a.VRAM.get(b, 0x45EC80)
        data = (ROOT / "extract" / f"{b}.bin").read_bytes()
        syms = ROOT / "build" / f"{b}_all_syms.ld"
        a.symbol_script(b, syms)
        for f in candidates(b):
            if (b, f[0]) not in done and not any((ROOT / "src" / b).rglob(f"{f[0]}.c")):
                jobs.append((b, f, syms, data[f[1] - base:f[2] - base]))
    jobs.sort(key=lambda j: j[1][2] - j[1][1])
    log(f"start (pid {os.getpid()}): {len(jobs)} functions left, {len(done)} already done, "
        f"{args.parallel}x{args.j} workers, {args.per_func}s each, {args.hours}h budget")

    matches = 0
    with ThreadPoolExecutor(args.parallel) as pool:
        futs = [pool.submit(run_one, j, args.per_func, args.j, deadline, args.max_base)
                for j in jobs]
        for i, fut in enumerate(futs, 1):
            func, result = fut.result()
            if result == "skipped":
                continue
            matches += result == "MATCH"
            log(f"[{i}/{len(jobs)}] {func}: {result}  (matches so far: {matches})")
    if STOPPING.is_set():
        log(f"stopped by signal: {matches} matches this run; rerun the same command to resume")
    else:
        log(f"end: {matches} matches. Run `make split && make -j` to fold them in.")
    PIDFILE.unlink(missing_ok=True)


if __name__ == "__main__":
    main()
