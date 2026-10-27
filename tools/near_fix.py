#!/usr/bin/env python3
"""Near-miss fixer: small source edits on drafts that compile but differ by a few instructions.

Inputs (drafts of functions that are not matched yet):
  notes/needs-claude/<func>_best.c|.cpp    an agent's closest source
  ~/Code/DQ8_w7/scratch/loop/<func>.c      the prompt loop's closest draft
  build/repair/<bin>/<func>.c              autodecomp's repaired m2c drafts, from
                                           this and the sibling DQ8_w* worktrees
Each draft is linked at its address (autodecomp.verify) and scored by the number
of differing words. Then, closest drafts first, edits that leave the meaning
alone are tried, a hill climb of at most --budget compiles per function:

  commute    `a + b` -> `b + a` (also * & | ^ == !=), `a < b` -> `b > a`
  swap       two adjacent statements exchanged (stores in another order)
  void       a callee whose result is never used declared `void`
  hexfloat   a float literal written as its exact hex form
  decl       two adjacent local declarations exchanged
  sign       a local or parameter of the other signedness (s32 <-> u32...)

A variant that scores better becomes the new base. Only a verify.py MATCH that
also passes tools/lint_contrived.py is written to src/<bin>/. None of the edits
adds anything CLAUDE.md calls contrived.

    near_fix.py [--budget 40] [--jobs 3] [--only func_X ...] [--dry-run] [--max-score 12] [--log]

First run (2026-10-27): 1310 drafts; 673 don't link or are too big, 560 are
more than 12 words off, 77 within 12 (29 within 4). No match: CodeWarrior
normalizes operand order itself (commute, void and hexfloat never changed a
byte), and only swap brought three drafts closer (12->11, 10->6, 10->6). The
remaining near misses are register allocation and scheduling, which needs the
permuter, not source edits.
"""
import argparse
import re
import struct
import subprocess
import sys
from collections import Counter
from multiprocessing import Pool
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import attempts  # noqa: E402
import autodecomp as ad  # noqa: E402
import dedup  # noqa: E402

LOOP_DRAFTS = Path.home() / "Code/DQ8_w7/scratch/loop"
OPERAND = r"(?:[A-Za-z_]\w*(?:(?:->|\.)\w+|\[[^\]\[]+\])*|0x[0-9A-Fa-f]+|\d+)"
# `a OP b` standing alone between an opening and a closing token, so that
# swapping the two sides cannot cross an operator of another precedence
CAST = r"(?:\(\s*(?:const\s+|unsigned\s+|signed\s+|struct\s+)*\w+[\s*]*\)\s*)?"
# a product binds tighter than + and the compares, so it moves as one side
TERM = rf"{CAST}{OPERAND}(?:\s*[*/%]\s*{CAST}{OPERAND})*"
COMMUTE = re.compile(rf"(?P<pre>(?:^|[(=,{{?:]|\breturn)\s*)(?P<a>{TERM})\s*"
                     rf"(?P<op>==|!=|<=|>=|<(?![<=])|>(?![>=])|\+(?![+=])|\*(?!=)|&(?![&=])|\|(?![|=])|\^(?!=))"
                     rf"\s*(?P<b>{TERM})(?P<post>\s*[),;?:\]])", re.M)
MIRROR = {"<": ">", ">": "<", "<=": ">=", ">=": "<="}
FLOAT = re.compile(r"(?<![\w.])(\d+\.\d*(?:[eE][-+]?\d+)?|\d*\.\d+(?:[eE][-+]?\d+)?)([fF]?)(?![\w.])")
PROTO = re.compile(r"^(?:extern\s+)?(M2C_UNK|s32|u32|s16|u16|s8|u8|int|void \*|s32 \*)\s+(\w+)\s*\(([^;{]*)\);", re.M)
DECL = re.compile(r"^\s+(?:(?:const|unsigned|signed|struct|union)\s+)*[A-Za-z_]\w*\s+\**\s*\w+\s*"
                  r"(?:\[[^\]]*\])?\s*(?:=[^;]*)?;\s*(?://.*|/\*.*\*/)?$")
NOT_DECL = re.compile(r"^\s*(?:return|goto|break|continue|case|else)\b")
SIMPLE = re.compile(r"^\s+[^\s{}].*;\s*$")
CONTROL = re.compile(r"\b(?:return|break|continue|goto|case|default|if|for|while|switch|do)\b|^\s*\w+:")


# ---- inputs ---------------------------------------------------------------------------

def inputs(rows):
    """[(func, path)] of drafts for functions without a source, best source first."""
    out = {}
    for p in sorted((ROOT / "notes/needs-claude").glob("*_best.c*")):
        out.setdefault(p.name.split("_best")[0], p)
    for p in sorted(LOOP_DRAFTS.glob("*.c")) if LOOP_DRAFTS.exists() else []:
        out.setdefault(p.stem, p)
    for wt in [ROOT] + sorted(ROOT.parent.glob("DQ8_w*")):
        for p in sorted((wt / "build/repair").glob("*/*.c*")):
            out.setdefault(p.stem, p)
    return [(f, p) for f, p in out.items() if f in rows and rows[f]["status"] != "matched"]


# ---- scoring --------------------------------------------------------------------------

def prepare(text, row):
    """The draft with this function's `// range:` line first."""
    rng = f"// range: 0x{row['addr']:X} 0x{row['addr'] + row['size']:X}"
    text = re.sub(r"^// range:.*\n?", "", text, flags=re.M)
    return rng + "\n" + text


def score(text, row, suffix, syms):
    """(score, verify result): differing words plus the size difference in words; 0 = match."""
    b = row["binary"]
    base = ad.VRAM.get(b, 0x45ECC0)
    data = DATA.setdefault(b, (ROOT / "extract" / f"{b}.bin").read_bytes())
    start, end = row["addr"], row["addr"] + row["size"]
    got = {}
    flags = re.search(r"^// flags: (.*)$", text, re.M)
    why = ad.verify(text, start, end, syms[b], data[start - base:end - base],
                    tuple(flags.group(1).split()) if flags else (), suffix, out_bytes=got)
    if why == "match":
        return 0, why
    if "text" not in got:
        return (900 if why == "size" else 1000), why
    mine, orig = got["text"], data[start - base:end - base]
    n = len(row["words"]) * 4
    diff = sum(1 for i in range(0, min(len(mine), n), 4) if mine[i:i + 4] != orig[i:i + 4])
    return diff + abs(len(mine) - n) // 4, why


DATA = {}


# ---- edits ----------------------------------------------------------------------------

def body_span(text, func):
    """(start, end) offsets of the function's body, between its braces."""
    m = re.search(rf"^[^\n;]*\b{re.escape(func)}\s*\([^;{{]*\)\s*\{{", text, re.M)
    if not m:
        return None
    depth, i = 1, m.end()
    while i < len(text) and depth:
        depth += {"{": 1, "}": -1}.get(text[i], 0)
        i += 1
    return m.end(), i - 1


def commutes(text, lo, hi):
    for m in COMMUTE.finditer(text, lo, hi):
        a, op, b = m.group("a"), m.group("op"), m.group("b")
        if a == b:
            continue
        new = f"{m.group('pre')}{b} {MIRROR.get(op, op)} {a}{m.group('post')}"
        yield "commute", text[:m.start()] + new + text[m.end():]


def line_spans(text, lo, hi):
    out, i = [], lo
    for line in text[lo:hi].split("\n"):
        out.append((i, i + len(line), line))
        i += len(line) + 1
    return out


def swaps(text, lo, hi):
    lines = line_spans(text, lo, hi)
    for (s1, e1, l1), (s2, e2, l2) in zip(lines, lines[1:]):
        if not (SIMPLE.match(l1) and SIMPLE.match(l2)):
            continue
        indent = lambda l: len(l) - len(l.lstrip())
        if indent(l1) != indent(l2) or l1.strip() == l2.strip():
            continue
        d1, d2 = bool(DECL.match(l1)) and not NOT_DECL.match(l1), bool(DECL.match(l2)) and not NOT_DECL.match(l2)
        if d1 != d2 or CONTROL.search(l1) or CONTROL.search(l2):
            continue
        yield ("decl" if d1 else "swap"), text[:s1] + l2 + "\n" + l1 + text[e2:]


def voids(text, lo, hi):
    body = text[lo:hi]
    for m in PROTO.finditer(text):
        if m.group(1) == "void":
            continue
        name = m.group(2)
        calls = re.findall(rf"^(.*)\b{name}\s*\(", body, re.M)
        if calls and all(not c.strip() for c in calls):
            yield "void", text[:m.start(1)] + "void" + text[m.end(1):]


def hexfloats(text, lo, hi):
    for m in FLOAT.finditer(text, lo, hi):
        v = float(m.group(1))
        if m.group(2):
            v = struct.unpack("<f", struct.pack("<f", v))[0]
        new = v.hex() + m.group(2)
        yield "hexfloat", text[:m.start()] + new + text[m.end():]


SIGNED = {"s8": "u8", "u8": "s8", "s16": "u16", "u16": "s16", "s32": "u32", "u32": "s32"}


def signs(text, lo, hi):
    """A local or a parameter declared with the other signedness."""
    head = text.rfind("\n", 0, lo)
    for m in re.finditer(r"\b(s8|u8|s16|u16|s32|u32)(\s+\**\s*\w+\s*[;,)=\[])", text[head:hi]):
        s = head + m.start(1)
        yield "sign", text[:s] + SIGNED[m.group(1)] + text[s + len(m.group(1)):]


RULES = (voids, hexfloats, commutes, swaps, signs)


def variants(text, func):
    span = body_span(text, func)
    if not span:
        return
    seen = set()
    for rule in RULES:
        for kind, new in rule(text, *span):
            if new != text and new not in seen:
                seen.add(new)
                yield kind, new


# ---- one function ---------------------------------------------------------------------

def lint_ok(text, suffix):
    tmp = ROOT / "build" / "near_fix" / f"lint_{abs(hash(text))}{suffix}"
    tmp.parent.mkdir(parents=True, exist_ok=True)
    tmp.write_text(text)
    r = subprocess.run([sys.executable, ROOT / "tools/lint_contrived.py", str(tmp)], capture_output=True, text=True)
    tmp.unlink()
    return r.returncode == 0


def fix(job):
    func, path, row, syms, budget, max_score = job
    suffix = ".cpp" if path.suffix == ".cpp" else ".c"
    text = prepare(path.read_text(errors="replace"), row)
    best, why = score(text, row, suffix, syms)
    first = best
    if best == 0:
        return func, path, row, first, 0, ("as-is" if lint_ok(text, suffix) else "lint"), text, 1
    if best > max_score:
        return func, path, row, first, best, why, None, 1
    spent, fired = 1, Counter()
    improved = True
    while improved and spent < budget:
        improved = False
        cand = None
        for kind, new in variants(text, func):
            if spent >= budget:
                break
            s, w = score(new, row, suffix, syms)
            spent += 1
            if s == 0:
                if lint_ok(new, suffix):
                    return func, path, row, first, 0, kind, new, spent
                continue
            if s < best and (cand is None or s < cand[0]):
                cand = (s, kind, new)
        if cand:
            best, kind, text = cand
            fired[kind] += 1
            improved = True
    return func, path, row, first, best, "+".join(fired) or why, None, spent


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--budget", type=int, default=40)
    p.add_argument("--jobs", type=int, default=3)
    p.add_argument("--max-score", type=int, default=12, help="skip drafts further off than this")
    p.add_argument("--only", nargs="+")
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--log", action="store_true", help="record each failed search in notes/attempts.jsonl")
    a = p.parse_args()
    rows = {r["func"]: r for r in dedup.functions()}
    todo = inputs(rows)
    if a.only:
        todo = [(f, q) for f, q in todo if f in a.only]
    syms = {}
    for b in {rows[f]["binary"] for f, _ in todo}:
        syms[b] = ROOT / "build" / f"{b}_all_syms.ld"
        ad.symbol_script(b, syms[b])
    print(f"{len(todo)} drafts of unmatched functions", flush=True)
    jobs = [(f, q, rows[f], syms, a.budget, a.max_score) for f, q in todo]
    made, hist, logged = [], Counter(), []
    with Pool(a.jobs) as pool:
        for func, path, row, first, best, how, text, spent in pool.imap_unordered(fix, jobs):
            band = "compile/link" if first >= 900 else "0" if first == 0 else "1-4" if first <= 4 else \
                   "5-12" if first <= 12 else "13+"
            hist[band] += 1
            print(f"{func:15} {first:5} -> {best:4}  {spent:3} compiles  {how}  ({path.relative_to(path.parents[2])})",
                  flush=True)
            if text is None and spent > 1:
                logged.append(attempts.record(
                    func, "tool", f"near_fix.py: {spent - 1} variants (commute, swap, void, hexfloat, decl, sign)",
                    how, best, str(path)))
            if text is None or how == "lint":
                continue
            out = ROOT / "src" / row["binary"] / f"{func}{'.cpp' if path.suffix == '.cpp' else '.c'}"
            if out.exists():
                continue
            if not a.dry_run:
                out.write_text(text)
            made.append((func, row["size"], how))
    if a.log and logged:
        attempts.append(logged)
    print("first scores (differing words):", dict(hist))
    print(f"{len(made)} matched ({sum(s for _, s, _ in made)} B):", dict(Counter(h for _, _, h in made)))


if __name__ == "__main__":
    main()
