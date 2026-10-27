#!/usr/bin/env python3
"""Prototypes known from the matched sources, as an m2c context.

Every matched function's definition is its real signature, and the callers of a
function not matched yet often agree on one in their extern declarations. m2c
drafts without them write `?` for a callee's return type and guess its argument
count, and autodecomp throws such drafts away. This collects them:

  - the definition of each tracked src/<bin>/*.c* file (always wins);
  - otherwise the most common extern declaration among the matched callers.

Types other than the basic ones (common.h's s32, u8... and C's own) become
`void *` behind a pointer; a struct passed by value drops the prototype.

    types_db.py      writes build/types_context.c and build/types_db.json

autodecomp.py passes the context to m2c and puts the prototypes a draft calls
at its top.
"""
import json
import re
import subprocess
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONTEXT = ROOT / "build" / "types_context.c"
DB = ROOT / "build" / "types_db.json"
BASIC = {"void", "s8", "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64",
         "char", "short", "int", "long", "float", "double", "signed", "unsigned", "const"}
TYPEDEFS = """typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
"""
DEF = re.compile(r"^(?!static\b)([A-Za-z_][\w \t*]*?)\b(func_[0-9A-F]{8}|[A-Za-z_]\w*)\s*\(([^;{)]*)\)\s*\{", re.M)
EXTERN = re.compile(r"^extern\s+([A-Za-z_][\w \t*]*?)\b(func_[0-9A-F]{8})\s*\(([^;{)]*)\)\s*;", re.M)


def basic(t):
    """A declaration's type with non-basic types made `void *`, or None (by value)."""
    t = re.sub(r"\b(struct|union|enum)\s+", "", " ".join(t.split()))
    stars = t.count("*")
    words = [w for w in re.findall(r"[A-Za-z_]\w*", t)]
    if all(w in BASIC for w in words):
        return t.replace(" *", "*").replace("*", " *").strip()
    return ("void " + "*" * stars).replace("*", " *").replace("  ", " ").strip() if stars else None


def param(p):
    p = p.strip()
    if p in ("", "void"):
        return "void"
    if p == "...":
        return p
    m = re.match(r"(.*?)(\b[A-Za-z_]\w*)?(\s*\[\s*\w*\s*\])?$", p)
    typ, arr = m.group(1) if m.group(2) and m.group(1).strip() else p, m.group(3)
    t = basic(typ + (" *" if arr else ""))
    return t


def proto(ret, name, params):
    r = basic(ret.replace("extern", "").replace("inline", ""))
    if r is None:
        return None
    ps = [param(p) for p in params.split(",")] if params.strip() else []
    if not ps:
        return None                      # `f()`: the arguments aren't known
    if any(p is None for p in ps):
        return None
    return f"{r} {name}({', '.join(ps)});"


def main():
    files = subprocess.run(["git", "ls-files", "src"], cwd=ROOT, capture_output=True, text=True).stdout.split()
    defined, votes = {}, defaultdict(Counter)
    for f in files:
        if "/asmfunc/" in f or not f.endswith((".c", ".cpp")):
            continue
        text = (ROOT / f).read_text(errors="replace")
        text = re.sub(r"/\*.*?\*/|//[^\n]*", "", text, flags=re.S)
        own = Path(f).stem
        for m in DEF.finditer(text):
            if m.group(2) == own:
                p = proto(m.group(1), own, m.group(3))
                if p:
                    defined[own] = p
        for m in EXTERN.finditer(text):
            p = proto(m.group(1), m.group(2), m.group(3))
            if p:
                votes[m.group(2)][p] += 1
    db = dict(defined)
    for name, c in votes.items():
        db.setdefault(name, c.most_common(1)[0][0])
    DB.write_text(json.dumps(db, indent=0, sort_keys=True))
    CONTEXT.write_text(TYPEDEFS + "\n".join(db[k] for k in sorted(db)) + "\n")
    print(f"{len(db)} prototypes ({len(defined)} from definitions) -> {CONTEXT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
