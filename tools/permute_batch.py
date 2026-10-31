#!/usr/bin/env python3
"""Run decomp-permuter over functions whose m2c draft compiles but mismatches.

    permute_batch.py [--hours 10] [--per-func 180] [--parallel 7] [-j 2] [--needs-claude]

--needs-claude takes the functions sessions gave up on with a register-only,
reorder-only or reorder+register CLASS (notes/needs-claude/) instead, starting from
the session's notes/needs-claude/<func>_best.c when there is one
(~/qwen-runs/permute-nightly.sh).

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
DONE = ROOT / "build" / "permute_batch.done"   # build/permute_nc.done with --needs-claude
NC_MODE = False
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


NEEDS_CLAUDE = ROOT / "notes" / "needs-claude"
CLOSE_CLASS = re.compile(r"CLASS (register-only|reorder-only|reorder\+register)")


def needs_claude_candidates(binary):
    """--needs-claude: functions a session gave up on with a register or reorder
    difference only, the kind of gap the permuter closes, smallest first."""
    want = set()
    for p in NEEDS_CLAUDE.glob("func_*.md"):
        text = p.read_text(errors="replace")
        if not CLOSE_CLASS.search(text):
            continue
        # the overlays share one load address, so an overlay function's name doesn't say
        # which binary it is: take it only for the overlay its note names most
        if binary != "SLES_539.74":
            named = re.findall(r"\b(TITLE|SHOP|MENU|CASINO|BATTLE)\b", text)
            if not named or max(set(named), key=named.count) != binary:
                continue
        want.add(p.stem)
    funcs, seen = [], set()
    for f in a.functions(binary):
        if f[0] in want and f[0] not in seen and not a.ALABEL.search(f[3]):
            funcs.append(f); seen.add(f[0])
    return sorted(funcs, key=lambda f: f[2] - f[1])


def candidates(binary):
    if NC_MODE:
        return needs_claude_candidates(binary)
    tsv = ROOT / "build" / f"autodecomp_{binary}.tsv"
    if not tsv.exists():
        return []
    latest = {}
    for line in tsv.read_text().splitlines():
        name, _, why = line.partition("\t")
        latest[name] = why
    want = {n for n, w in latest.items() if w in ("mismatch", "size", "repaired")}
    # a function with a global `alabel` entry point inside it cannot become C
    # at all, whatever order its statements end up in
    funcs = [f for f in a.functions(binary) if f[0] in want and not a.ALABEL.search(f[3])]
    return sorted(funcs, key=lambda f: f[2] - f[1])


def base_source(binary, func, asm):
    """(source, note): what to permute, and how to describe it in src/.

    The permuter parses the draft with pycparser and cannot work on one that
    does not compile, so pick the first variant CodeWarrior accepts: the saved
    repaired draft if we have one, otherwise the plainest m2c candidate that
    compiles, and failing that repair one now.
    """
    best = NEEDS_CLAUDE / f"{func}_best.c"
    if NC_MODE and best.exists():  # the session's closest attempt, minus its header lines
        return re.sub(r"^// (range|auto|flags):.*\n", "", best.read_text(), flags=re.M), "a session's best draft"
    saved = ROOT / "build" / "repair" / binary / f"{func}.c"
    if saved.exists():  # m2c draft whose types tools/repair.py fixed for CodeWarrior
        return saved.read_text(), "m2c draft with casts added"
    from repair import compile_src, repair  # imports autodecomp; do it on demand
    plain = sorted((c for _, c in a.candidates(func, asm)),
                   key=lambda s: ("typedef struct" in s, a.SWAP_CMP.sub(r"\3 \2 \1", s) != s))
    for source in plain[:3]:
        ok, _ = compile_src(source)
        if ok:
            return source, "m2c draft"
    for source in plain[:1]:
        fixed = repair(source)
        if not fixed:
            continue
        dest = ROOT / "build" / "repair" / binary / f"{func}.c"
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(fixed)
        return fixed, "m2c draft with casts added"
    return None, None


TYPEDEF_BLOCK = re.compile(r"^typedef (?:struct|union)[^;{]*\{[^}]*\}\s*\w+\s*;\n", re.M | re.S)


def hoist_typedefs(c):
    """Move struct/union definitions above the externs that use them.

    m2c emits `extern S_D_x *D_...;` before the `typedef struct {...} S_D_x;`,
    which CodeWarrior accepts (the tag is implicit) and pycparser — the
    permuter's parser — rejects outright.
    """
    blocks = [m.group(0) for m in TYPEDEF_BLOCK.finditer(c)]
    if not blocks:
        return c
    first = re.search(r"^extern ", c, re.M)
    if not first:
        return c
    c = TYPEDEF_BLOCK.sub("", c)
    first = re.search(r"^extern ", c, re.M)
    return c[: first.start()] + "".join(blocks) + c[first.start():]


BASE_NOTE = {}   # func -> what its permutation started from, for the src/ header


def setup(binary, func, asm):
    source, BASE_NOTE[func] = base_source(binary, func, asm)
    if not source:
        return None
    source = hoist_typedefs(source)
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
            dest.write_text(f"// range: 0x{start:X} 0x{end:X}\n// auto: {BASE_NOTE.get(func, 'm2c draft')} "
                            "+ decomp-permuter, verified byte-exact\n" + src)
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
    ap.add_argument("--needs-claude", action="store_true",
                    help="permute the register/reorder-only needs-claude functions instead "
                         "(their session's best draft when there is one); own done file")
    args = ap.parse_args()
    global NC_MODE, DONE
    NC_MODE = args.needs_claude
    if NC_MODE:
        DONE = ROOT / "build" / "permute_nc.done"

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
        base = a.VRAM.get(b, 0x45ECC0)
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
