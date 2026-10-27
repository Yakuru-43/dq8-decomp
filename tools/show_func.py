#!/usr/bin/env python3
"""Print what a session needs about one function, and nothing else.

Reading all of build/queue.tsv or a whole asm/<bin>/*.s segment puts thousands of
lines into the context, where they stay for the rest of the session.  This prints
the function's queue row, its asm alone (vram address and instruction, without the
file offset and raw bytes), the functions and data it references, and which
drafts or notes already exist for it.

    show_func.py              the next row to claim (todo, blocker none, <= 1024 B)
    show_func.py func_XXXXXXXX
    show_func.py func_XXXXXXXX --raw    keep the offset and bytes columns
"""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
QUEUE = ROOT / "build" / "queue.tsv"
INSN = re.compile(r"^(\s*)/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]+ \*/(\s*.*)$")  # delay slots keep their extra space
REF = re.compile(r"\b((?:func|D|jtbl)_[0-9A-Fa-f]{8})\b")


def queue_rows():
    if not QUEUE.exists():
        return [], []
    lines = QUEUE.read_text().splitlines()
    return lines[0].split("\t"), [line.split("\t") for line in lines[1:] if line]


def next_row(rows):
    for r in rows:
        if len(r) >= 7 and r[0] == "todo" and r[6] == "none" and int(r[5]) <= 1024:
            return r
    return None


def find_asm(binary, func):
    """The lines from `glabel func` to `endlabel func`, or None."""
    for f in sorted((ROOT / "asm" / binary).glob("*.s")):
        text = f.read_text(errors="replace")
        start = text.find(f"glabel {func}\n")
        if start < 0:
            continue
        end = text.find(f"endlabel {func}\n", start)
        body = text[start:end if end >= 0 else len(text)].splitlines()
        return f.relative_to(ROOT), body
    return None, None


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("func", nargs="?")
    p.add_argument("--raw", action="store_true", help="keep the file offset and bytes columns")
    args = p.parse_args()

    head, rows = queue_rows()
    if args.func is None:
        r = next_row(rows)
        if r is None:
            sys.exit("no eligible todo row")
        print("\t".join(head))
        print("\t".join(r))
        return
    func = args.func
    row = next((r for r in rows if len(r) > 3 and r[3] == func), None)
    if row:
        print("\t".join(head))
        print("\t".join(row))
    binary = row[2] if row else "SLES_539.74"

    path, body = find_asm(binary, func)
    if body is None:
        sys.exit(f"{func}: no glabel in asm/{binary}/")
    print(f"\n{path} ({len(body) - 1} lines)")
    for line in body:
        m = INSN.match(line)
        print(line if args.raw or not m else f"{m.group(1)}{m.group(2)}{m.group(3)}")

    refs = sorted(set(REF.findall("\n".join(body[1:]))) - {func})
    if refs:
        print("\nreferences: " + " ".join(refs))
    have = [p for p in (ROOT / "build" / "repair" / binary / f"{func}.c",
                        ROOT / "src" / binary / f"{func}.c",
                        ROOT / "src" / binary / f"{func}.cpp",
                        ROOT / "notes" / "needs-claude" / f"{func}.md") if p.exists()]
    for p in have:
        print(f"exists: {p.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
