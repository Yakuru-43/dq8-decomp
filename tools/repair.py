#!/usr/bin/env python3
"""Fix m2c's type mistakes until CodeWarrior accepts the file.

m2c has to guess a type for every field and local, and CodeWarrior is strict
where GCC is lenient: a pointer used as an integer, an integer dereferenced as
a pointer, a callee whose parameter list m2c guessed wrong. The drafts are
otherwise correct, so what is missing is a cast in the right place.

`repair()` compiles the draft, reads CodeWarrior's first error (it echoes the
offending line with a caret under the operand) and applies a rule that
rewrites that spot. Rules return several candidates and the first one that
compiles wins, so a wrong guess costs a compile rather than a function.

Nothing here can produce a false positive: the caller still compares bytes.

    python tools/repair.py --only func_00140490   # debug one function
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp as A  # noqa: E402

INTS = ("int", "s32", "u32", "s16", "u16", "s8", "u8", "s64", "u64", "long", "unsigned",
        "M2C_UNK", "M2C_UNK8", "M2C_UNK16", "M2C_UNK32", "M2C_UNK64")
TYPES = set(INTS + ("f32", "f64", "char", "void", "struct", "union", "enum"))
ERR_LINE = re.compile(r"^#\s+(\d+): (.*)$")
QUOTED = re.compile(r"'([^']*)'")


def compile_src(c):
    """(ok, stderr) for a draft on its own."""
    with tempfile.TemporaryDirectory() as tmp:
        src, obj = f"{tmp}/f.c", f"{tmp}/f.o"
        Path(src).write_text(c)
        r = subprocess.run([A.TC / "wibo", A.MWCC, "-c", *A.CFLAGS, src, "-o", obj],
                           capture_output=True, text=True)
        return r.returncode == 0, r.stderr


def first_error(stderr):
    """(lineno, col, message, echoed line) for the first error, or None."""
    lines = stderr.splitlines()
    for i, line in enumerate(lines):
        m = ERR_LINE.match(line)
        if not m or i + 1 >= len(lines) or "Error:" not in lines[i + 1]:
            continue
        caret = lines[i + 1]
        if "^" not in caret:
            continue
        msg = []
        for cont in lines[i + 2:]:
            if not cont.startswith("# ") or cont.startswith("###") or ERR_LINE.match(cont) or "Error:" in cont:
                break
            msg.append(cont[2:].strip())
        return int(m.group(1)), caret.index("^") - line.index(m.group(2)), " ".join(msg), m.group(2)
    return None


# --- expression helpers --------------------------------------------------------

def is_ptr(typ):
    return typ.strip().endswith("*")


BREAK_CHARS = " \t,;=+-*/%<>!&|^~"


def operand_at(line, col):
    """(start, end) of the subexpression the caret marks the end of.

    CodeWarrior puts the caret one past the offending expression, so the walk
    goes left from there: balanced brackets first, then the name in front of
    them (`M2C_FIELD(...)`, `a->b`), stopping at an operator.
    """
    if not line:
        return None
    end = min(col, len(line))
    while end > 0 and line[end - 1] in " ;,":
        end -= 1
    i, depth = end, 0
    while i > 0:
        ch = line[i - 1]
        if ch in ")]":
            depth += 1
        elif ch in "([":
            depth -= 1
        elif depth == 0 and ch in BREAK_CHARS:
            break
        i -= 1
    if depth or i == end:
        return None
    name = re.search(r"[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)*$", line[:i])
    if name:
        i = name.start()
    return i, end


def unary_operand(line, i):
    """Index just past the primary expression that starts at i."""
    if line[i:i + 1] == "(":  # `*(a + b)`: the operand is the parenthesised group
        end = match_paren(line, i)
    else:
        m = re.match(r"[A-Za-z_]\w*", line[i:])
        if not m:
            return None
        end = i + m.end()
    if end is None:
        return None
    while end < len(line):
        if line[end] == "(":
            close = match_paren(line, end)
            if close is None:
                return None
            end = close
            continue
        m = re.match(r"(->|\.)[A-Za-z_]\w*|\[[^\]]*\]", line[end:])
        if not m:
            break
        end += m.end()
    return end


def base_span(text):
    """(start, end) of the primary expression that ends `text` (after rstrip)."""
    t = text.rstrip()
    if not t:
        return None
    start = len(t) - 1
    if t[-1] == ")":
        depth = 0
        while start >= 0:
            depth += (t[start] == ")") - (t[start] == "(")
            if depth == 0:
                break
            start -= 1
        if start < 0:
            return None
    m = re.search(r"[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)*$", t[:start] if t[-1] == ")" else t)
    if t[-1] != ")":
        return (m.start(), len(t)) if m else None
    return (m.start() if m else start, len(t))


def enclosing_arg(line, col):
    """(start, end) of the call argument (or whole expression) holding `col`."""
    i, depth = min(col, len(line)), 0
    start = 0
    while i > 0:
        i -= 1
        ch = line[i]
        if ch in ")]":
            depth += 1
        elif ch in "([":
            if depth == 0:
                start = i + 1
                break
            depth -= 1
        elif ch == "," and depth == 0:
            start = i + 1
            break
    depth, end = 0, start
    while end < len(line):
        ch = line[end]
        if ch in "([":
            depth += 1
        elif ch in ")]":
            if depth == 0:
                break
            depth -= 1
        elif ch == "," and depth == 0:
            break
        end += 1
    body = line[start:end].strip().rstrip(";")
    if not body:
        return None
    return line.index(body, start), line.index(body, start) + len(body)


def cast_pointer_bases(line):
    """Variants with the base of `base + n` cast to `char *`.

    m2c types a pointer field as `char **` and then does `field + 8`; only
    `char *` may be offset in standard C, which is what CodeWarrior enforces.
    """
    out = []
    for i, ch in enumerate(line):
        if ch not in "+-" or not binary_at(line, i):
            continue
        span = base_span(line[:i])
        if span:
            out.append(line[:span[0]] + "(char *) " + line[span[0]:])
    return out[:3]


def deref_positions(line):
    """Positions of `*` used as a dereference (not as multiplication)."""
    out = []
    for i, ch in enumerate(line):
        if ch != "*":
            continue
        before = line[:i].rstrip()[-1:] or ""
        if before and (before.isalnum() or before in "_)]*"):
            continue  # `a * b`
        out.append(i)
    return out


def match_paren(line, open_i):
    """Index just past the parenthesis that opens at open_i, or None."""
    depth, i = 0, open_i
    while i < len(line):
        depth += (line[i] == "(") - (line[i] == ")")
        i += 1
        if depth == 0:
            return i
    return None


def binary_at(text, i):
    """Is the operator at i a binary one (left operand present, not `-=`, `->`)?"""
    j = i - 1
    while j >= 0 and text[j] == " ":
        j -= 1
    if j < 0 or not (text[j].isalnum() or text[j] in "_)]*"):
        return False
    rest = text[i + 1:]
    return not rest.startswith(("=", "->")) and not rest.startswith(text[i])


def top_ops(text, ops):
    """[(op, index)] for outermost binary operators, longest operator first."""
    out, depth = [], 0
    for i, ch in enumerate(text):
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        elif depth == 0 and ch in "+-":
            for op in sorted(ops, key=len, reverse=True):
                if text.startswith(op, i) and binary_at(text, i):
                    out.append((op, i))
                    break
    return out


def assignment_rhs(text):
    """(lhs, rhs_start, rhs) for a plain `x = ...;`, else None."""
    depth = 0
    for i, ch in enumerate(text):
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        elif ch == "=" and depth == 0:
            before = text[:i].rstrip()[-1:] or ""
            if text[i + 1:i + 2] == "=" or before in "+-*/%&|^<>=!":
                continue
            rhs = text[i + 1:]
            if rhs.strip() and rhs.strip() != ";":
                return text[:i].strip(), i + 1, rhs
            return None
    return None


def wrap(line, span, cast):
    s, e = span
    return line[:s] + f"({cast}) ({line[s:e]})" + line[e:]


def dedup(items):
    seen, out = set(), []
    for i in items:
        if i not in seen and i.strip():
            seen.add(i)
            out.append(i)
    return out


# --- rules: each returns rewritten sources, best first -------------------------

def rule_deref(c, lineno, col, msg, line):
    """`pointer/array required`: something untyped is dereferenced.

    `*(temp_v1 + 4)` and `*var_a3` both need the address cast to a pointer
    type; the original instruction is a word access, so try `s32` first and
    `char *` (as the value read) second.
    """
    out = []
    for pos in sorted(deref_positions(line), key=lambda p: abs(p - col)):
        i = pos + 1
        while i < len(line) and line[i] == " ":
            i += 1
        after = re.match(r"([A-Za-z_]\w*)\s*\*", line[i:])
        if after and after.group(1) in TYPES:
            continue  # already `*(T *) (...)`
        end = unary_operand(line, i)
        if end is None:
            continue
        for cast in ("s32", "char **", "f32"):
            out.append(line[:pos] + f"*( {cast} *) " + line[i:end] + line[end:])
        break
    return [substitute(c, lineno, new) for new in dedup(out)]


def rule_conversion(c, lineno, col, msg, line):
    """`illegal implicit conversion from 'A' to 'B'`."""
    types = QUOTED.findall(msg)
    if len(types) < 2:
        return []
    from_t, to_t = types[0], types[1]
    rhs = assignment_rhs(line)
    spans = []
    if rhs:
        body = rhs[2].rstrip().rstrip(";")
        spans.append((rhs[1], rhs[1] + len(body)))
    span = operand_at(line, col)
    if span:
        spans.append(span)
    cast = "s32" if not is_ptr(to_t) else to_t.strip()
    variants = []
    if not rhs and is_ptr(from_t) != is_ptr(to_t):
        # the value is a call argument: cast the whole argument, not the
        # operand under the caret (which is usually just one side of a `+`)
        arg = enclosing_arg(line, col)
        if arg:
            variants.append(wrap(line, arg, cast))
    # a `char **` field being offset: retype the base, keep the raw offset.
    # This is the fix when the value is a call argument and there is no
    # assignment to cast.
    if is_ptr(from_t):
        variants += cast_pointer_bases(line)
    # `ptr - int` is scaled pointer arithmetic; the original is a plain difference
    if rhs and is_ptr(from_t) and not is_ptr(to_t):
        for op, idx in top_ops(rhs[2], ["-", "+"]):
            left, right = rhs[2][:idx].strip(), rhs[2][idx + len(op):].strip().rstrip(";")
            if left and right:
                variants.append(line[:rhs[1]] + f" (s32) ((char *) {left} {op} (char *) {right});")
            break
    variants += [wrap(line, s, cast) for s in spans if s[0] < s[1]]
    return [substitute(c, lineno, v) for v in dedup(variants)]


def rule_mismatch(c, lineno, col, msg, line):
    """`type mismatch 'A' and 'B'` / `illegal operands 'A' - 'B'`."""
    variants = cast_pointer_bases(line)
    span = operand_at(line, col)
    if span:
        variants += [wrap(line, span, "char *"), wrap(line, span, "s32")]
    rhs = assignment_rhs(line)
    body, base = (rhs[2], rhs[1]) if rhs else (line, 0)
    for op, idx in top_ops(body, ["-", "+"]):
        left, right = body[:idx].strip(), body[idx + len(op):].strip().rstrip(";")
        if left and right:
            inner = f"(char *) {left} {op} (char *) {right}"
            variants.append(line[:base] + (f" (s32) ({inner});" if rhs else f" ({inner});"))
        break
    return [substitute(c, lineno, v) for v in dedup(variants)]


def rule_undefined(c, lineno, col, msg, line):
    """`undefined identifier 'X'`: declare it and let the link test decide."""
    m = re.search(r"undefined identifier '(\w+)'", msg)
    if not m or re.search(rf"^\s*(extern|typedef).*\b{m.group(1)}\b", c, re.M):
        return []
    name = m.group(1)
    decl = f"extern void {name}();" if re.search(rf"\b{name}\s*\(", line) else f"extern s32 {name};"
    return [add_decl(c, decl)]


def rule_call(c, lineno, col, msg, line):
    """`function call 'X' does not match`: m2c guessed the parameter list."""
    m = re.search(r"function call '?(\w+)'?", msg)
    if not m:
        return []
    new, n = re.subn(rf"^(\S[^;]*?\b{m.group(1)})\s*\([^;{{)]*\)\s*;", r"\1();", c, count=1, flags=re.M)
    return [new] if n else []


RULES = [
    (re.compile(r"pointer/array required"), rule_deref),
    (re.compile(r"illegal implicit conversion"), rule_conversion),
    (re.compile(r"type mismatch"), rule_mismatch),
    (re.compile(r"illegal operands"), rule_mismatch),
    (re.compile(r"undefined identifier"), rule_undefined),
    (re.compile(r"does not match|too (many|few) arguments"), rule_call),
]


def substitute(c, lineno, new):
    """Replace source line `lineno` with `new`, keeping its indentation.

    CodeWarrior echoes the line stripped, so rules work on stripped text.
    """
    src = c.splitlines(True)
    indent = src[lineno - 1][: len(src[lineno - 1]) - len(src[lineno - 1].lstrip())]
    src[lineno - 1] = indent + new.strip() + "\n"
    return "".join(src)


def add_decl(c, decl):
    lines = c.splitlines()
    i = max((n for n, l in enumerate(lines) if l.startswith("#include")), default=0) + 1
    return "\n".join(lines[:i]) + "\n" + decl + "\n" + "\n".join(lines[i:]) + "\n"


def tidy(c):
    """Undo the spacing the rewrites leave behind: `x =(y)`, `( y`."""
    c = re.sub(r"[ \t]*=[ \t]*\(", "= (", c)
    return re.sub(r"(?<=\S)\([ \t]+", "(", c)


PLACEHOLDER = r"\(?\s*(?:second half of f64|carry bit)\s*\)?"


def drop_placeholders(c):
    """Remove m2c's `second half of f64` argument markers.

    A `double` argument occupies a register pair; m2c lists the second half as
    a pseudo-argument that is not C. The value is already passed by the
    argument in front of it, so the marker simply goes away.
    """
    c = re.sub(r",\s*" + PLACEHOLDER, "", c)
    return re.sub(PLACEHOLDER + r"\s*,\s*", "", c)


def repair(c, max_rounds=10, budget=24):
    """Rewrite `c` until CodeWarrior accepts it, or give up.

    One error at a time: a rewrite is kept when it compiles or at least moves
    the first error somewhere else, so a file with three type mistakes is
    repaired in three rounds.
    """
    if c is None:
        return None
    c = drop_placeholders(c)
    ok, stderr = compile_src(c)
    for _ in range(max_rounds):
        if ok or budget <= 0:
            break
        err = first_error(stderr)
        if err is None:
            return None
        lineno, col, msg, line = err
        for pattern, rule in RULES:
            if not pattern.search(msg):
                continue
            for cand in rule(c, lineno, col, msg, line)[:3]:
                if cand == c:
                    continue
                budget -= 1
                ok2, stderr2 = compile_src(cand)
                nxt = first_error(stderr2)
                # progress = compiles, or the same complaint is gone (the column
                # alone moving only means the line grew)
                if ok2 or (nxt and (nxt[0], nxt[2]) != (err[0], err[2])):
                    c, ok, stderr = cand, ok2, stderr2
                    break
            else:
                continue
            break
        else:
            return None
    return tidy(c) if ok else None


def main():
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", required=True)
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--draft", default="mips-gcc-c")
    args = ap.parse_args()
    for name, start, end, asm, _ in A.functions(args.bin):
        if name != args.only:
            continue
        c = A.draft(name, asm, args.draft)
        c = c and A.fix_externs(c, asm)
        if not c:
            print("no draft")
            return
        r = repair(c)
        print(r if r else "REPAIR FAILED")
        return
    print("not found")


if __name__ == "__main__":
    main()
