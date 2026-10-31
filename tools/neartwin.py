#!/usr/bin/env python3
"""Near-twins: functions that differ from a matched one only in their constants.

tools/dedup.py settles exact copies (same bytes once addresses are hidden). Many
more functions are the same code with another field offset, another loop bound or
another constant: their bytes are equal once the 16-bit immediates are hidden too
(loads/stores, addiu, slti, andi, ori...; branch offsets stay, so the shape must
be the same). For such a function, the matched twin's source is retargeted as in
dedup.py, then every literal that produced one of the twin's immediates is given
this function's value:

  - the immediates that differ are read by position (twin value a, ours b);
  - a literal of value a in the source becomes b; so does a literal of value a/k
    (an array index scaled by k = 2, 4, 8, 16: it becomes b/k) or -a (`x - 4`
    compiles to addiu -4);
  - first every occurrence at once, then each occurrence alone when a value
    appears several times (at most MAX_VARIANTS sources per pair).

A source is kept only when verify.py says MATCH and tools/lint_contrived.py
passes. Sources with a jump table are skipped, as are overlay copies that would
reference the main binary (see dedup.py).

    neartwin.py scan               count the candidates (functions, bytes)
    neartwin.py apply [--dry-run]  write the matches to src/
    neartwin.py apply --only func_X

Run tools/funcdb.py first; after apply, keep_funcs.py, `make split && make -j`, gate.
"""
import argparse
import itertools
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import dedup  # noqa: E402
import verify  # noqa: E402

MAX_VARIANTS = 40
UNSIGNED_OPS = {0x0C, 0x0D, 0x0E}            # andi, ori, xori: zero-extended
SCALES = (1, -1, 2, 4, 8, 16)
# an integer literal that is not part of an identifier or a float
LITERAL = re.compile(r"(?<![\w.])(0[xX][0-9A-Fa-f]+|\d+)([uUlL]*)(?![\w.])")


def is_imm(w):
    op = w >> 26
    return op >= 8 and op not in dedup.BRANCH_OPS


def near_key(words, start):
    m, _ = dedup.masked(words, start)
    return tuple(w & 0xFFFF0000 if is_imm(w) else w for w in m)


def imm_value(w):
    v = w & 0xFFFF
    return v if w >> 26 in UNSIGNED_OPS else dedup.sext16(v)


def imm_pairs(src_words, src_addr, dst_words, dst_addr):
    """{twin value: our value} for the immediates that differ, or None on a conflict."""
    sm, _ = dedup.masked(src_words, src_addr)
    dm, _ = dedup.masked(dst_words, dst_addr)
    pairs = {}
    for s, d in zip(sm, dm):
        if s == d:
            continue
        a, b = imm_value(s), imm_value(d)
        if pairs.get(a, b) != b:
            return None
        pairs[a] = b
    return pairs


def candidates():
    """[(row, [matched twin rows])] for unmatched functions with a matched near-twin
    and no exact matched twin (dedup.py's job)."""
    rows = list(dedup.functions())
    sources = dedup.tracked_sources()
    exact, near = defaultdict(list), defaultdict(list)
    for r in rows:
        if len(r["words"]) < 4:
            continue
        m, _ = dedup.masked(r["words"], r["addr"])
        exact[tuple(m)].append(r)
        near[near_key(r["words"], r["addr"])].append(r)
    done = lambda r: r["status"] == "matched" and r["func"] in sources
    settled = {r["func"] for g in exact.values() if any(map(done, g)) for r in g}
    out = []
    for g in near.values():
        twins = [r for r in g if done(r)]
        out += [(r, twins) for r in g if twins and r["status"] != "matched" and r["func"] not in settled]
    return out, rows, sources


def occurrences(body, pairs):
    """[(a, [(start, end, new text)])]: where each differing value is written."""
    out = []
    taken = set()
    for a, b in sorted(pairs.items(), key=lambda p: -abs(p[0])):
        spots = []
        for m in LITERAL.finditer(body):
            if m.start() in taken:
                continue
            lit = m.group(1)
            if len(lit) > 1 and lit[0] == "0" and lit[1] not in "xX":
                continue                                   # octal: leave it alone
            v = int(lit, 0)
            for k in SCALES:
                if v * k != a or b % k or b // k < 0:
                    continue
                n = b // k
                text = (hex(n).upper().replace("0X", "0x") if m.group(1).lower().startswith("0x") else str(n))
                spots.append((m.start(), m.end(), text + m.group(2)))
                break
        if not spots:
            return None
        taken |= {s[0] for s in spots}
        out.append((a, spots))
    return out


def variants(body, occ):
    """Sources with the new values: all occurrences first, then one at a time."""
    def build(chosen):
        out, last = [], 0
        for s, e, t in sorted(chosen):
            out += [body[last:s], t]
            last = e
        return "".join(out) + body[last:]
    every = [spot for _, spots in occ for spot in spots]
    yield build(every)
    n = 1
    for i, (a, spots) in enumerate(occ):
        if len(spots) < 2:
            continue
        others = [spot for j, (_, sp) in enumerate(occ) if j != i for spot in sp]
        for spot in spots:
            if n >= MAX_VARIANTS:
                return
            n += 1
            yield build(others + [spot])
    # two values that share occurrences: each pairing, still bounded
    multi = [(a, spots) for a, spots in occ if len(spots) > 1]
    if len(multi) == 2:
        for x, y in itertools.product(multi[0][1], multi[1][1]):
            if n >= MAX_VARIANTS:
                return
            n += 1
            rest = [spot for a, sp in occ if len(sp) == 1 for spot in sp]
            yield build(rest + [x, y])


def lint_ok(path):
    r = subprocess.run([sys.executable, ROOT / "tools/lint_contrived.py", str(path)],
                       cwd=ROOT, capture_output=True, text=True)
    return r.returncode == 0


def apply(dry, only=None):
    cands, rows, sources = candidates()
    by_func = {(r["binary"], r["func"]): r for r in rows}
    names = defaultdict(dict)
    for (b, f), r in by_func.items():
        names[b][r["addr"]] = f
    syms, made, tried = {}, [], 0
    why_not = defaultdict(int)
    for row, twins in cands:
        b, f, addr, size = row["binary"], row["func"], row["addr"], row["size"]
        if only and f not in only:
            continue
        tried += 1
        out = None
        for twin in twins:
            src = ROOT / sources[twin["func"]]
            text = src.read_text()
            if "// rodata:" in text:
                why_not["jump table"] += 1
                continue
            res = dedup.rename_map((twin["binary"], twin["addr"], twin["words"]), (b, addr, row["words"]), names)
            pairs = imm_pairs(twin["words"], twin["addr"], row["words"], addr)
            if res is None or pairs is None:
                why_not["conflict"] += 1
                continue
            new = dedup.retarget(text, *res)
            new = re.sub(r"^// range: \S+ \S+", f"// range: 0x{addr:X} 0x{addr + size:X}", new, count=1, flags=re.M)
            if not re.search(rf"\b{re.escape(f)}\s*\(", new):
                why_not["name"] += 1
                continue
            if b != "SLES_539.74" and any(int(x, 16) < 0x45ECC0 for x in dedup.HEXNAME_ADDR.findall(new)):
                why_not["overlay to main"] += 1
                continue
            head, _, body = new.partition("\n")
            occ = occurrences(body, pairs)
            if occ is None:
                why_not["value not a literal"] += 1
                continue
            out = ROOT / "src" / b / f"{f}{src.suffix}"
            if out.exists():
                break
            for v in variants(body, occ):
                out.write_text(head + "\n" + v)
                if verify.check(out, syms) == "match" and lint_ok(out):
                    made.append((f, size))
                    print(f"MATCH     {out.relative_to(ROOT)}  (from {twin['func']}, {len(pairs)} values)")
                    if dry:
                        out.unlink()
                    break
                out.unlink()
            else:
                why_not["no variant matched"] += 1
                continue
            break
    print(f"{len(made)} matched ({sum(s for _, s in made)} B) of {tried} near-twins tried")
    for k, n in sorted(why_not.items(), key=lambda x: -x[1]):
        print(f"  {k}: {n} twin pairs")


def scan():
    cands, _, _ = candidates()
    by = defaultdict(lambda: [0, 0])
    for r, _ in cands:
        by[r["binary"]][0] += 1
        by[r["binary"]][1] += r["size"]
    print(f"{len(cands)} unmatched functions with a matched near-twin, {sum(r['size'] for r, _ in cands)} B")
    for b, (n, s) in sorted(by.items()):
        print(f"  {b:12} {n:5} {s:8} B")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("cmd", choices=["scan", "apply"])
    p.add_argument("--dry-run", action="store_true")
    p.add_argument("--only", nargs="+")
    a = p.parse_args()
    if a.cmd == "scan":
        scan()
    else:
        apply(a.dry_run, set(a.only) if a.only else None)


if __name__ == "__main__":
    main()
