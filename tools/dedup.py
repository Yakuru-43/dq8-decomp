#!/usr/bin/env python3
"""Identical functions: one match settles every copy.

Many functions are byte-for-byte the same code at another address, differing only
in the addresses they call or load. This groups every function of the six binaries
by its masked body (call targets, %hi/%lo halves and gp-relative offsets hidden)
from the original bytes, so matched and unmatched functions are compared alike.

    dedup.py scan              build/dedup_groups.json and a summary
    dedup.py apply [--dry-run] for every unmatched function with a matched twin:
                               the twin's source with its addresses moved to this
                               function's, written to src/ only when verify.py
                               says MATCH
    dedup.py show func_X       the function's group

apply renames by position: where the matched copy calls or loads address a, this
copy uses b, so every `name_a` in the source becomes `name_b` (an identifier
pointing inside an object moves by the same offset). Sources with a jump table
(`// rodata:`) are skipped. Run tools/funcdb.py first; after apply, the usual
keep_funcs.py, `make split && make -j`, gate.
"""
import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from autodecomp import VRAM  # noqa: E402
import verify  # noqa: E402

BINARIES = ["SLES_539.74", "BATTLE", "CASINO", "MENU", "SHOP", "TITLE"]
GP = 0x3E7270
GROUPS = ROOT / "build" / "dedup_groups.json"
HEXNAME = re.compile(r"\b([A-Za-z_]\w*?_)([0-9A-F]{8})\b")
HEXNAME_ADDR = re.compile(r"\b(?:func|D|jtbl)_([0-9A-F]{8})\b")
BRANCH_OPS = {1, 4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17}


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def masked(words, start):
    """(masked words, [(index, address)]): the addresses a copy is free to change."""
    out, refs, hi = [], [], {}
    for i, w in enumerate(words):
        op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op in (2, 3):                                   # j / jal
            refs.append((i, ((start + 4 * i) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)))
            w &= 0xFC000000
        elif op == 0x0F:                                   # lui
            hi[rt] = (w & 0xFFFF) << 16
            w &= 0xFFFF0000
        elif op == 0 and w & 0x3F in (0x21, 0x2D) and (rs in hi or rt in hi):
            hi[(w >> 11) & 31] = hi.get(rs, hi.get(rt))    # addu/daddu: an indexed %hi base
        elif op not in BRANCH_OPS and op >= 8 and op != 0x0F and (rs in hi or rs == 28):
            base = hi.get(rs, GP) if rs != 28 else GP
            refs.append((i, (base + sext16(w & 0xFFFF)) & 0xFFFFFFFF))
            w &= 0xFFFF0000
        out.append(w)
    return out, refs


def functions():
    """Rows of build/funcdb.tsv, with the original bytes (trailing padding dropped)."""
    data = {b: (ROOT / "extract" / f"{b}.bin").read_bytes() for b in BINARIES}
    lines = (ROOT / "build" / "funcdb.tsv").read_text().splitlines()
    head = lines[0].split("\t")
    for line in lines[1:]:
        r = dict(zip(head, line.split("\t")))
        b, addr, size = r["binary"], int(r["addr"], 16), int(r["size"])
        off = addr - VRAM.get(b, 0x45ECC0)
        words = list(struct.unpack_from(f"<{size // 4}I", data[b], off))
        while words and words[-1] == 0:
            words.pop()
        r.update(addr=addr, size=size, words=words)
        yield r


def tracked_sources():
    out = subprocess.run(["git", "ls-files", "src"], cwd=ROOT, capture_output=True, text=True).stdout
    return {Path(p).stem: p for p in out.split() if "/asmfunc/" not in p and p.endswith((".c", ".cpp"))}


def scan():
    groups = defaultdict(list)
    for r in functions():
        if len(r["words"]) < 4:                            # stubs: too little to tell copies apart
            continue
        m, _ = masked(r["words"], r["addr"])
        key = hashlib.sha1(struct.pack(f"<{len(m)}I", *m)).hexdigest()
        groups[key].append([r["binary"], r["func"], r["addr"], r["size"], r["status"]])
    multi = {k: v for k, v in groups.items() if len(v) > 1}
    GROUPS.write_text(json.dumps(multi, indent=0))
    open_ = [f for g in multi.values() for f in g if f[4] != "matched"]
    free = [f for g in multi.values() if any(x[4] == "matched" for x in g) for f in g if f[4] != "matched"]
    later = sum(sum(sorted(x[3] for x in g if x[4] != "matched")[:-1] or [0])
                for g in multi.values() if not any(x[4] == "matched" for x in g))
    print(f"{len(multi)} groups of identical functions, {sum(map(len, multi.values()))} functions")
    print(f"unmatched with a twin: {len(open_)} ({sum(f[3] for f in open_)} B)")
    print(f"  with a matched twin now: {len(free)} ({sum(f[3] for f in free)} B)")
    print(f"  settled later by one match per group: {later} B")


def rename_map(src_rows, dst_rows, names):
    """{identifier in the matched source: identifier for the copy}, or None on a conflict."""
    (sb, sa, sw), (db, da, dw) = src_rows, dst_rows
    _, srefs = masked(sw, sa)
    _, drefs = masked(dw, da)
    pairs = [(sa, da)] + [(a, b) for (_, a), (_, b) in zip(srefs, drefs)]
    by_name = {}
    for a, b in pairs:
        na, nb = names[sb].get(a), names[db].get(b)
        if na and nb and na != nb:
            if by_name.get(na, nb) != nb:
                return None
            by_name[na] = nb
    return by_name, pairs


def retarget(text, by_name, pairs):
    """The source with its names and hex-suffixed identifiers moved to the copy's addresses.

    One pass over the identifiers: renaming one after another would chain (a copy
    named after its twin, then renamed again because the twin is also a callee)."""
    def move(m):
        word = m.group(0)
        if word in by_name:
            return by_name[word]
        h = HEXNAME.fullmatch(word)
        if not h:
            return word
        x = int(h.group(2), 16)
        best = min(((a - x, b) for a, b in pairs if 0 <= a - x < 0x10000), default=None)
        return word if best is None else f"{h.group(1)}{best[1] - best[0]:08X}"
    head, _, body = text.partition("\n")
    return head + "\n" + re.sub(r"\b[A-Za-z_]\w*\b", move, body)


def apply(dry):
    if not GROUPS.exists():
        sys.exit("run `dedup.py scan` first")
    rows = {(r["binary"], r["func"]): r for r in functions()}
    names = defaultdict(dict)
    for (b, f), r in rows.items():
        names[b][r["addr"]] = f
    sources = tracked_sources()
    syms, made, failed = {}, [], 0
    for group in json.loads(GROUPS.read_text()).values():
        done = [g for g in group if g[4] == "matched" and g[1] in sources]
        for b, f, addr, size, status in group:
            if status == "matched" or not done:
                continue
            for sb, sf, sa, ssize, _ in done:
                src = ROOT / sources[sf]
                text = src.read_text()
                if "// rodata:" in text:
                    continue
                res = rename_map((sb, sa, rows[(sb, sf)]["words"]), (b, addr, rows[(b, f)]["words"]), names)
                if res is None:
                    continue
                new = retarget(text, *res)
                new = re.sub(r"^// range: \S+ \S+", f"// range: 0x{addr:X} 0x{addr + size:X}", new, count=1, flags=re.M)
                # verify compares bytes, not names: the copy must define its own symbol
                if not re.search(rf"\b{re.escape(f)}\s*\(", new):
                    continue
                # an overlay's C can't reach the main binary yet: its calls there came
                # from splat's undefined_funcs list, which only covers asm
                if b != "SLES_539.74" and any(int(x, 16) < 0x45ECC0 for x in HEXNAME_ADDR.findall(new)):
                    continue
                out = ROOT / "src" / b / f"{f}{src.suffix}"
                if out.exists():
                    break
                out.write_text(new)
                why = verify.check(out, syms)
                if why == "match":
                    made.append(out.relative_to(ROOT).as_posix())
                    print(f"MATCH     {out.relative_to(ROOT)}  (from {sf})")
                    if dry:
                        out.unlink()
                    break
                out.unlink()
            else:
                failed += 1
    print(f"{len(made)} matched, {failed} tried without a match")


def show(func):
    for group in json.loads(GROUPS.read_text()).values():
        if any(g[1] == func for g in group):
            for b, f, addr, size, status in group:
                print(f"{b:12} {f}  {size:5} B  {status}")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("cmd", choices=["scan", "apply", "show"])
    p.add_argument("func", nargs="?")
    p.add_argument("--dry-run", action="store_true")
    a = p.parse_args()
    if a.cmd == "scan":
        scan()
    elif a.cmd == "apply":
        apply(a.dry_run)
    else:
        show(a.func)


if __name__ == "__main__":
    main()
