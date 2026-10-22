#!/usr/bin/env python3
"""Refuse C that only exists to steer the compiler (CLAUDE.md, "no contrived C").

    lint_contrived.py <file.c|.cpp|.h>...

A file prints one line per finding (path:line: rule: text) and the exit
status is 1 if any file has one.  A file that carries `// permuter-artifact`
in its first lines is known debt waiting for a rewrite and is skipped.
Rules:
  volatile        `volatile` outside a hardware register or data another
                  thread/interrupt writes (mark those lines `// hw-register`
                  or `// thread-shared`)
  while-0         `do { } while (0)` or any other `while (0)`
  comma-expr      a comma operator inside parentheses: `(0, p)`, `if (a, b)`
  pad-local       a local named pad* that nothing reads
  pasted-typedef  a typedef of a name common.h already defines
  no-common-h     the file doesn't `#include "common.h"`
  self-assign     `x = x;`
  noop-mask       `& 0xFFFFFFFF` on a 32-bit value
  empty-stmt      a line that is only `;`
  double-negate   `- -0x10` and the like
  inline-asm      `asm`/`__asm__` blocks: the bytes must come from C
  include-asm     INCLUDE_ASM / GLOBAL_ASM / INCLUDE_RODATA or `.incbin`
  pragma          any `#pragma` (optimisation or scheduling switches)
  text-section    data placed in a `.text` section with __attribute__
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
COMMON = (ROOT / "include" / "common.h").read_text()
COMMON_TYPES = set(re.findall(r"typedef\s[^;]*?\b(\w+)\s*;", COMMON))
NOT_CALLS = {"return", "if", "while", "switch", "sizeof", "case"}

VOLATILE = re.compile(r"\bvolatile\b")
WHILE_0 = re.compile(r"\bwhile\s*\(\s*0\s*\)")
PAD_DECL = re.compile(r"^\s*(?:(?:unsigned|signed|const)\s+)*\w+\s+\**\s*(pad\w*)\s*(?:\[[^\]]*\])?\s*;", re.M)
STRUCT_BODY = re.compile(r"\b(?:struct|union|class)\b[^{;()]*\{[^{}]*\}")
TYPEDEF = re.compile(r"\btypedef\b[^;{]*?(?:\{[^}]*\}\s*)?(\w+)\s*;", re.S)
SELF_ASSIGN = re.compile(r"(?<![\w.>])(\w+)\s*=\s*\1\s*;")
NOOP_MASK = re.compile(r"&\s*0x[fF]{8}[uU]?\b(?![lL])")
EMPTY_STMT = re.compile(r"^[ \t]*;[ \t]*$", re.M)
DOUBLE_NEG = re.compile(r"(?<![-\w)\]])-\s*-\s*(?=[\w(])")
INLINE_ASM = re.compile(r"\b(?:__asm__|__asm|asm)\b")
INCLUDE_ASM = re.compile(r"\b(?:INCLUDE_ASM|GLOBAL_ASM|INCLUDE_RODATA)\b|\.incbin\b")
PRAGMA = re.compile(r"^[ \t]*#[ \t]*pragma\b", re.M)
TEXT_SECTION = re.compile(r"section\s*\(\s*\"\.text")


def strip(text):
    """Blank out comments and string/char literals, keeping line breaks and offsets."""
    def blank(m):
        return re.sub(r"[^\n]", " ", m.group(0))
    return re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', blank, text, flags=re.S)


def comma_exprs(code):
    """Offsets of '(' groups that hold a top-level comma and are not a call,
    a declaration's parameter list or a `for` header."""
    found = []
    stack = []
    for i, ch in enumerate(code):
        if ch == "(":
            j = i - 1
            while j >= 0 and code[j].isspace():
                j -= 1
            word = re.search(r"(\w+)$", code[:j + 1])
            prev = code[j] if j >= 0 else ""
            if word and word.group(1) not in NOT_CALLS:
                kind = "call"           # call, macro, declaration, for (...)
            elif prev in ")]":
                kind = "call"           # (*fp)(a, b), table[i](a, b)
            else:
                kind = "expr"
            if word and word.group(1) == "for":
                kind = "call"
            stack.append([i, kind, False])
        elif ch == ")" and stack:
            start, kind, comma = stack.pop()
            if kind == "expr" and comma:
                found.append(start)
        elif ch == "," and stack:
            stack[-1][2] = True
        elif ch in "{};" and stack:
            stack.clear()               # unbalanced: give up on this statement
    return found


def lint(path):
    raw = Path(path).read_text(errors="replace")
    if "// permuter-artifact" in "\n".join(raw.splitlines()[:5]):
        return []
    code = strip(raw)
    lines = raw.splitlines()
    out = []

    def hit(offset, rule):
        n = code.count("\n", 0, offset) + 1
        out.append(f"{path}:{n}: {rule}: {lines[n - 1].strip() if n <= len(lines) else ''}")

    for m in VOLATILE.finditer(code):
        n = code.count("\n", 0, m.start())
        if "hw-register" not in lines[n] and "thread-shared" not in lines[n]:
            hit(m.start(), "volatile")
    for m in WHILE_0.finditer(code):
        hit(m.start(), "while-0")
    for off in comma_exprs(code):
        hit(off, "comma-expr")
    # pad fields inside a struct or union are layout, not locals
    bodies = code
    while True:
        blanked = STRUCT_BODY.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), bodies)
        if blanked == bodies:
            break
        bodies = blanked
    for m in PAD_DECL.finditer(bodies):
        if len(re.findall(rf"\b{re.escape(m.group(1))}\b", code)) == 1:
            hit(m.start(1), "pad-local")
    for m in TYPEDEF.finditer(code):
        if m.group(1) in COMMON_TYPES:
            hit(m.start(), "pasted-typedef")
    if Path(path).suffix != ".h" and not re.search(r'#\s*include\s*"common\.h"', raw):
        out.append(f"{path}:1: no-common-h: add #include \"common.h\"")
    for m in SELF_ASSIGN.finditer(code):
        hit(m.start(), "self-assign")
    for m in NOOP_MASK.finditer(code):
        hit(m.start(), "noop-mask")
    for m in EMPTY_STMT.finditer(code):
        hit(m.start(), "empty-stmt")
    for m in DOUBLE_NEG.finditer(code):
        hit(m.start(), "double-negate")
    for m in INLINE_ASM.finditer(code):
        hit(m.start(), "inline-asm")
    # these live in strings or directives, so look at the text with only comments removed
    nocomment = re.sub(r"//[^\n]*|/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), raw, flags=re.S)
    for m in INCLUDE_ASM.finditer(nocomment):
        hit(m.start(), "include-asm")
    for m in PRAGMA.finditer(nocomment):
        hit(m.start(), "pragma")
    for m in TEXT_SECTION.finditer(nocomment):
        hit(m.start(), "text-section")
    return out


def main():
    bad = 0
    for p in sys.argv[1:]:
        found = lint(p)
        bad += bool(found)
        for line in found:
            print(line)
    if bad:
        print(f"lint: {bad} of {len(sys.argv) - 1} files have contrived C (see CLAUDE.md)", file=sys.stderr)
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
