#!/usr/bin/env python3
"""Mass-decompile functions with m2c and keep only byte-exact matches.

For every CodeWarrior-compiled function (game_* asm files) that has no source yet:
  1. m2c drafts C for the function alone
  2. extern declarations are adjusted to the addressing the original uses
     (absolute %hi/%lo -> section(".data"), $gp-relative -> plain small object)
  3. mwccps2 compiles it (flags as in the Makefile)
  4. the object is linked at the function's real address with every known
     symbol defined at its real address, and the bytes are compared exactly,
     padding included. Objects that emit their own data are rejected.
Matches are written to src/<binary>/<func>.c with a `// range:` header that
tools/gen_configs.py turns into a split.

    autodecomp.py [--bin SLES_539.74] [--jobs 14] [--limit N] [--only func_...]
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from functools import lru_cache
from multiprocessing import Pool
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from gen_configs import region_prefix  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
TC = ROOT / ".toolchain"
BIN = TC / "usr/bin"
MWCC = TC / "mwcps2/3.0.1b151-050317/mwccps2.exe"
CFLAGS = ["-O3", "-nostdinc", "-stderr", f"-I{ROOT / 'include'}"]
VRAM = {"SLES_539.74": 0x100000}

GLABEL = re.compile(r"^glabel (\w+)", re.M)
ALABEL = re.compile(r"^[ \t]*alabel ", re.M)
ANY_LABEL = re.compile(r"^(?:glabel|dlabel|jlabel|alabel) (\w+)\n\s+/\* \w+ ([0-9A-F]{8}) ", re.M)
INSN_ADDR = re.compile(r"^\s+/\* \w+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", re.M)
HILO = re.compile(r"%(?:hi|lo)\((\w+)")
GPREL = re.compile(r"%gp_rel\((\w+)")
EXTERN = re.compile(r"^extern (.+?)\s+(\*{0,2})(\w+)(\[\])?;", re.M)


def functions(binary):
    """[(name, start, end, asm_text, file)] for every function, sorted by address."""
    out = []
    for f in sorted((ROOT / "asm" / binary).glob("*.s")):
        text = f.read_text(errors="replace")
        for m in re.finditer(r"^(?:nonmatching \w+, 0x\w+\n\n)?glabel (\w+)\n.*?^endlabel \1\n", text, re.M | re.S):
            a = INSN_ADDR.search(m.group(0))
            if a:
                out.append([m.group(1), int(a.group(1), 16), None, m.group(0), f.name])
    # functions already moved to src/ still bound their neighbours
    for p in (ROOT / "src" / binary).rglob("*.c*"):
        m = re.match(r"// range: (0x[0-9A-Fa-f]+)", p.read_text())
        if m:
            out.append([None, int(m.group(1), 16), None, None, None])
    out.sort(key=lambda x: x[1])
    for cur, nxt in zip(out, out[1:]):
        cur[2] = nxt[1]
    return [tuple(x) for x in out if x[2] and x[0]]


def symbol_script(binary, path):
    """Linker script defining every known symbol at its address."""
    syms = {}
    for f in (ROOT / "asm" / binary).rglob("*.s"):
        for m in ANY_LABEL.finditer(f.read_text(errors="replace")):
            syms[m.group(1)] = int(m.group(2), 16)
    for f in (ROOT / "src" / binary).rglob("*.c"):
        m = re.match(r"// range: (0x[0-9A-Fa-f]+)", f.read_text())
        if m:
            syms.setdefault(f.stem, int(m.group(1), 16))
    for f in (ROOT / "linker").glob(f"{binary}_undefined_*_auto.txt"):
        for m in re.finditer(r"^(\w+) = (0x[0-9A-Fa-f]+);", f.read_text(), re.M):
            syms.setdefault(m.group(1), int(m.group(2), 16))
    for f in (ROOT / "config").glob(f"symbol_addrs_{binary}*.txt"):
        for m in re.finditer(r"^(\w+) = (0x[0-9A-Fa-f]+);", f.read_text(), re.M):
            syms.setdefault(m.group(1), int(m.group(2), 16))
    path.write_text("".join(f"{n} = 0x{a:X};\n" for n, a in sorted(syms.items())))


def draft(name, asm, target="mips-gcc-c"):
    """m2c output for one function, or None."""
    with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False) as t:
        t.write(asm)
    try:
        r = subprocess.run([str(Path(sys.executable).parent / "m2c"), "--valid-syntax", "--globals", "used",
                            "--no-cache", "-t", target, "-f", name, t.name],
                           capture_output=True, text=True, timeout=60)
    except subprocess.TimeoutExpired:
        return None
    finally:
        os.unlink(t.name)
    if r.returncode or "M2C_ERROR" in r.stdout:
        return None
    c = r.stdout
    # m2c writes `?` for types it could not infer; ternaries are fine
    if re.search(r"(^|[(,]\s*|extern )\?[\s*]", c, re.M):
        return None
    # m2c drops unused leading parameters (e.g. `this`) but keeps argN numbering:
    # restore them so the used ones land in the right registers
    def fill_params(m):
        params = [p.strip() for p in m.group(2).split(",")] if m.group(2).strip() not in ("", "void") else []
        idx = {int(re.search(r"arg(\d+)$", p).group(1)): p for p in params if re.search(r"arg\d+$", p)}
        if len(idx) != len(params) or not idx or max(idx) + 1 == len(idx):
            return m.group(0)
        full = [idx.get(i, f"s32 arg{i}") for i in range(max(idx) + 1)]
        return f"{m.group(1)}({', '.join(full)}) {{"
    c = re.sub(rf"^(\S.*\b{name})\(([^)]*)\) \{{", fill_params, c, count=1, flags=re.M)
    # m2c relies on GCC's void-pointer arithmetic; CodeWarrior rejects it
    c = re.sub(r"\bvoid \*", "char *", c)
    if re.search(r"\bsubroutine_arg\d+\b", c):
        return None  # an incoming stack argument: no C for a caller's frame slot
    return declare_stack_locals(c)


SP_SLOT = re.compile(r"\bsp[0-9A-F]{2,}\b")


def declare_stack_locals(c):
    """Type the stack slots m2c used but never declared.

    m2c names a slot after its offset from $sp and declares the ones it tracked
    through stores; a slot that only ever gets loaded appears bare. The type
    decides which load CodeWarrior emits, so guess float where the slot is used
    next to a float and int everywhere else — a wrong guess costs a mismatch,
    never a wrong match.
    """
    declared = {m.group(1) for m in
                re.finditer(r"^\s*\w[\w \t*]*?\b(sp[0-9A-F]{2,})\s*(?:\[[^]]*\])?;", c, re.M)}
    missing = sorted(set(SP_SLOT.findall(c)) - declared)
    if not missing:
        return c
    floats = set(re.findall(r"^\s*f(?:32|64)\s+(\w+)\s*(?:=|;)", c, re.M))
    lines = c.splitlines()
    decls = []
    for slot in sorted(missing, key=lambda s: int(s[2:], 16)):
        use = re.compile(rf"\b{slot}\b")
        is_float = any(use.search(line) and (floats & set(re.findall(r"\b\w+\b", line)) or
                                             re.search(r"[-+*/<>=]=?\s*-?\s*\d*\.\d", line))
                       for line in lines if use.search(line))
        decls.append(f"    {'f32' if is_float else 's32'} {slot};")
    # after the declarations the draft already has: CodeWarrior lays the frame
    # out in declaration order, so appending to that block keeps the offsets
    i = next((n for n, line in enumerate(lines) if line.rstrip().endswith("{")), None)
    if i is None:
        return c
    while i + 1 < len(lines) and re.fullmatch(r"\s*(\w[\w \t*]*\s+\w+\s*(\[[^]]*\])?|)\s*(=[^;]*)?;",
                                              lines[i + 1]):
        i += 1
    lines[i + 1:i + 1] = decls
    return "\n".join(lines) + "\n"


def fix_externs(c, asm):
    hilo, gprel = set(HILO.findall(asm)), set(GPREL.findall(asm))

    def repl(m):
        typ, stars, sym, arr = m.group(1), m.group(2), m.group(3), m.group(4) or ""
        if sym in hilo and not arr:
            # `extern T *p;` is as absolute as `extern T p;`: the star belongs
            # to the name, and m2c writes both forms
            return f'extern {typ} {stars}{sym} __attribute__((section(".data")));'
        if sym in gprel and arr:
            return None  # unknown-size array can't be $gp-relative
        return m.group(0)

    out = []
    for line in c.splitlines():
        m = EXTERN.match(line)
        if m:
            line = repl(m)
            if line is None:
                return None
        out.append(line)
    return '#include "common.h"\n\n' + "\n".join(out) + "\n"


def sections(obj):
    r = subprocess.run([BIN / "mips64-linux-gnu-readelf", "-SW", obj], capture_output=True, text=True).stdout
    out = {}
    for m in re.finditer(r"\]\s+(\S+)\s+\S+\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)", r):
        out[m.group(1)] = int(m.group(2), 16)
    return out


VU0 = re.compile(r"\b(lqc2|sqc2|qmtc2|qmfc2|ctc2|cfc2|v[a-z0-9]+\.[xyzw]+|vsqrt|vdiv|vrsqrt|vwaitq|vnop|vcallms\w*)\b")
ASM_INSN = re.compile(r"^\s+/\* \w+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(.*)$")
ASM_LABEL = re.compile(r"^\s*\.L([0-9A-F]+):")
ASM_JUMP = re.compile(r"^(?:j|jal|bal)\s+(\w+)\s*$")
ASM_BRANCH = re.compile(r"^b\w*\s+.*,\s*(\w+)\s*$")


def asm_function(name, asm):
    """CodeWarrior `asm` function reproducing the original instructions, or None.

    Used for hand-written VU0 code, which m2c cannot express.
    """
    out = [f"asm void {name}(void)", "{"]
    targets = []
    for line in asm.splitlines():
        m = ASM_LABEL.match(line)
        if m:
            out.append(f"L_{m.group(1)}:")
            continue
        m = ASM_INSN.match(line)
        if not m:
            continue
        ins = m.group(1).split("#")[0].strip()
        if ins.startswith(".") or "%" in ins or ">>" in ins:
            return None  # data words / relocations: not handled
        ins = re.sub(r"\.L([0-9A-F]+)", r"L_\1", ins).replace("$", "")
        # jump/branch targets must be declared or mwccps2 calls them undefined labels
        m2 = ASM_JUMP.match(ins) or ASM_BRANCH.match(ins)
        if m2 and not m2.group(1).startswith("L_") and m2.group(1) not in targets:
            targets.append(m2.group(1))
        out.append(f"    {ins}")
    out.append("}")
    decls = "".join(f"extern void {t}(void);\n" for t in targets)
    return '#include "common.h"\n\n' + decls + ("\n" if decls else "") + "\n".join(out) + "\n"


# `a == b` -> `b == a`: CodeWarrior keeps source operand order in compares
SWAP_CMP = re.compile(r"(?<![\w>.\]])(\w+(?:->\w+|\.\w+|\[\w+\])*) (==|!=) (\w+(?:->\w+|\.\w+|\[\w+\])*)(?![\w(\[])")


TYPE_SIZE = {"s8": 1, "u8": 1, "s16": 2, "u16": 2, "s32": 4, "u32": 4, "f32": 4, "M2C_UNK": 4,
             "s64": 8, "u64": 8, "f64": 8}
FIELD = re.compile(r"M2C_FIELD\((\w+), ([\w ]+?\**) \*, (0x[0-9A-F]+|\d+)\)")


def field_size(typ):
    return 4 if typ.endswith("*") else TYPE_SIZE.get(typ)


def structify(c):
    """Turn M2C_FIELD(var, T *, off) on plain pointer variables into var->unkOFF.

    M2C_FIELD is (char *)var + off arithmetic, which CodeWarrior keeps in a
    register as a common subexpression; real struct members use offset
    addressing like the original code.
    """
    fields = {}
    for var, typ, off in FIELD.findall(c):
        fields.setdefault(var, {}).setdefault(int(off, 0), set()).add(typ.strip())
    defs, renamed = [], []
    for var, offs in fields.items():
        decl = re.search(rf"\bchar \*{var}\b(?=[,);])", c)
        if not decl:
            continue
        # pointer arithmetic on the variable would change meaning with a struct type
        if re.search(rf"\b{var}\s*[-+\[]|[-+]\s*{var}\b", FIELD.sub("", c)):
            continue
        layout, pos, ok = [], 0, True
        for off in sorted(offs):
            types = offs[off]
            size = field_size(next(iter(types)))
            if len(types) != 1 or size is None or off < pos or off % size:
                ok = False
                break
            if off > pos:
                layout.append(f"    char pad{pos:X}[0x{off - pos:X}];")
            layout.append(f"    {next(iter(types))} unk{off:X};")
            pos = off + size
        if not ok:
            continue
        defs.append(f"typedef struct {{\n" + "\n".join(layout) + f"\n}} S_{var};\n")
        renamed.append(var)
    if not renamed:
        return None
    for var in renamed:
        c = re.sub(rf"\bchar \*{var}\b(?=[,);])", f"S_{var} *{var}", c)
        c = re.sub(rf"M2C_FIELD\({var}, [\w ]+?\** \*, (0x[0-9A-F]+|\d+)\)",
                   lambda m: f"{var}->unk{int(m.group(1), 0):X}", c)
    # struct definitions go right before the function definition
    m = re.search(r"^[^\s/#].*\)\s*\{\s*$", c, re.M)
    return c[:m.start()] + "\n".join(defs) + "\n" + c[m.start():] if m else None


def block_end(text, open_i):
    """Index of the `}` closing the brace that opens at open_i, or None."""
    depth = 0
    for i in range(open_i, len(text)):
        depth += (text[i] == "{") - (text[i] == "}")
        if depth == 0:
            return i
    return None


def guard_form(c, name):
    """Rewrite `if (cond) { rest of the function }` as an early return.

    The two spellings generate different branches — one tests and jumps *into*
    the body, the other tests and jumps *around* it — and CodeWarrior does not
    pick one: it follows the source. m2c guesses.
    """
    decl = re.search(rf"^void\s+{name}\([^)]*\)\s*\{{", c, re.M)
    if not decl:
        return None
    body_end = block_end(c, decl.end() - 1)
    if body_end is None:
        return None
    body = c[decl.end():body_end]
    m = re.search(r"^[ \t]*if[ \t]*\((.*)\)[ \t]*\{", body, re.M)
    if not m or block_end(body, m.end() - 1) != len(body.rstrip()) - 1:
        return None  # something after the if would also run in the original
    inner = body[m.end():len(body.rstrip()) - 1]
    if "\n" not in inner:
        return None  # a one-liner: CodeWarrior inlines the branch either way
    dedented = re.sub(r"^    ", "", inner, flags=re.M)
    guard = f"\n    if (!({m.group(1)})) {{\n        return;\n    }}\n{dedented}"
    return c[:decl.end()] + body[:m.start()] + guard + c[body_end:]


UNPROTO = re.compile(r"^(\S[^;(\n]*?\b(\w+))\(\);", re.M)
FLOAT_LIT = re.compile(r"(?<![\w.])\d+\.\d*f?\b|(?<![\w.])\.\d+f?\b")


def call_args(c, fn):
    """The argument strings of the first call `fn(...)` in the body, or None."""
    m = re.search(rf"(?<![\w>.]){fn}\((?!\);)", c[c.find("{"):] if "{" in c else c)
    if not m:
        return None
    body = c[c.find("{"):]
    i, depth, start, args = m.end(), 1, m.end(), []
    while i < len(body) and depth:
        ch = body[i]
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        elif ch == "," and depth == 1:
            args.append(body[start:i].strip())
            start = i + 1
        i += 1
    last = body[start:i - 1].strip()
    if last:
        args.append(last)
    return args


def float_protos(c):
    """Prototype the unprototyped callees that take a float, or None.

    m2c declares callees it knows nothing about as `T f();`. C promotes a float
    passed to such a function to double, which CodeWarrior converts with the
    soft-float helper `fptodp` -- an undefined symbol at link time, and never
    the original code. Each argument is typed from the first call: f32 when
    its expression is float (a float literal, or a name declared f32), a
    pointer when it takes an address or names a pointer, s32 otherwise.
    """
    floats = set(re.findall(r"\bf(?:32|64)\s+(\w+)\s*[;=,)\[(]", c))
    ptrs = set(re.findall(r"\b\w+\s*\*+\s*(\w+)\s*[;=,)\[]", c))
    changed = False

    def arg_type(a):
        if a.startswith("&") or a.startswith('"') or re.fullmatch(r"\w+", a) and a in ptrs:
            return "void *"
        if re.match(r"\((?:s|u)(?:8|16|32|64)\)", a):
            return "s32"
        names = set(re.findall(r"\b(\w+)\b", a))
        return "f32" if FLOAT_LIT.search(a) or names & floats else "s32"

    def repl(m):
        nonlocal changed
        args = call_args(c, m.group(2))
        if not args:
            return m.group(0)
        types = [arg_type(a) for a in args]
        if "f32" not in types:
            return m.group(0)
        changed = True
        return f"{m.group(1)}({', '.join(types)});"

    out = UNPROTO.sub(repl, c)
    return out if changed else None


def candidates(name, asm):
    """Yield (kind, source) attempts, most likely first."""
    seen = set()
    for target in ("mips-gcc-c", "mipsee-mwcc-c"):
        c = draft(name, asm, target)
        c = c and fix_externs(c, asm)
        if not c:
            continue
        # unprototyped callees: m2c often disagrees with itself on argument counts
        unproto = re.sub(r"^(\S[^;(]*?\b\w+)\([^;]*\);(\s*/\* (?:extern|static) \*/)", r"\1();\2", c, flags=re.M)
        bases = [b for b in (structify(c), structify(unproto)) if b] + [c, unproto]
        bases += [p for p in map(float_protos, bases) if p]
        for v in [x for b in bases for x in (b, SWAP_CMP.sub(r"\3 \2 \1", b))]:
            if v not in seen:
                seen.add(v)
                yield "m2c", v
        for b in (c, unproto):  # the same body with the test inverted
            g = guard_form(b, name)
            if g and g not in seen:
                seen.add(g)
                yield "m2c", g
    if VU0.search(asm):
        c = asm_function(name, asm)
        if c:
            yield "asm", c


JTBL_REF = re.compile(r"%hi\((jtbl_[0-9A-F]{8})\)")
JTBL = re.compile(r"^dlabel (jtbl_([0-9A-F]{8}))\n(.*?)^enddlabel \1\n", re.M | re.S)


@lru_cache(maxsize=8)
def jump_tables(binary):
    """name -> (address, [target addresses]) for every jtbl_ in asm/<binary>/data."""
    out = {}
    for f in (ROOT / "asm" / binary / "data").glob("*.s"):
        for m in JTBL.finditer(f.read_text(errors="replace")):
            out[m.group(1)] = (int(m.group(2), 16),
                               [int(w, 16) for w in re.findall(r"\.word\s+(0x[0-9A-Fa-f]+)", m.group(3))])
    return out


def function_tables(binary, asm):
    """{name: (address, [targets])} for the jump tables a function's asm uses.

    splat ends a table at the next label, so the alignment zeros after it look
    like entries: a table is the run of words that point into the function.
    Raises KeyError if a table is not in the data disassembly.
    """
    addrs = [int(a, 16) for a in INSN_ADDR.findall(asm)]
    lo, hi = min(addrs), max(addrs)
    out = {}
    for n in sorted(set(JTBL_REF.findall(asm))):
        start, words = jump_tables(binary)[n]
        k = 0
        while k < len(words) and lo <= words[k] <= hi:
            k += 1
        out[n] = (start, words[:k])
    return out


def rodata_range(binary, asm):
    """(start, end) of the jump tables a function's asm uses, None if it uses none.

    CodeWarrior writes a function's switch tables one after another into its
    .rodata; the src file gets `// rodata: START END` and its .rodata replaces
    that range of the data segment (tools/gen_configs.py, tools/postsplit.py).
    Raises KeyError if a table is not in the data disassembly.
    """
    tables = function_tables(binary, asm)
    if not tables:
        return None
    spans = [(s, s + 4 * len(w)) for s, w in tables.values()]
    return min(s for s, _ in spans), max(e for _, e in spans)


def with_jump_tables(binary, asm):
    """The function's asm plus its jump tables, as m2c needs them to write a `switch`.

    The data disassembly has the tables as raw addresses and the text one has
    no labels at the case targets: add `.L` labels there and `.word .L...` tables.
    """
    tables = function_tables(binary, asm)
    if not tables:
        return asm
    targets = {w for _, words in tables.values() for w in words}
    have = {int(a, 16) for a in re.findall(r"^\s*\.L([0-9A-F]{8}):", asm, re.M)}
    out = []
    for line in asm.splitlines():
        m = INSN_ADDR.match(line)
        if m and int(m.group(1), 16) in targets - have:
            out.append(f"  .L{m.group(1)}:")
        out.append(line)
    out += ["", ".section .rodata", ""]
    for n, (_, words) in tables.items():
        out.append(f"glabel {n}")
        out += [f"    .word .L{w:08X}" for w in words]
    return "\n".join(out) + "\n"


ADDR_SYM = re.compile(r"\b((?:func|jtbl|D)_[0-9A-F]{8})\b")


@lru_cache(maxsize=8)
def known_symbols(path):
    """Names the link already defines."""
    return frozenset(re.findall(r"^(\w+) =", Path(path).read_text(), re.M))


def symbol_script_for(c, syms_ld, tmp):
    """A script that also defines the address-named symbols m2c had to invent.

    m2c calls anything without a real name after its address (`D_0034B220`).
    splat labels an address only where its heuristics found something, so a
    draft can point at a name no object defines -- inside a data blob, or at a
    function another one was merged over -- and the link fails. The name *is*
    the address, so defining it there is exactly what the real link does.
    """
    missing = sorted(set(ADDR_SYM.findall(c)) - known_symbols(str(syms_ld)))
    if not missing:
        return syms_ld
    out = Path(tmp) / "syms.ld"
    out.write_text(Path(syms_ld).read_text()
                   + "".join(f"{n} = 0x{n.split('_', 1)[1]};\n" for n in missing))
    return out


def verify(c, start, end, syms_ld, orig, flags=(), suffix=".c", rodata=None, out_bytes=None):
    """'match' if `c` compiles to exactly the original bytes, else the failure reason.
    `suffix` is the source file's extension: mwcc compiles a .cpp file as C++.
    `rodata` is (address, original bytes) for a file whose .rodata (a switch's
    jump table) replaces that range of the data segment: the object's .rodata
    is linked there and must be exactly those bytes. A dict passed as
    `out_bytes` gets the linked "text" and "rodata" (tools/jtbl.py --diff)."""
    with tempfile.TemporaryDirectory() as tmp:
        src, obj, elf, out = (f"{tmp}/f{suffix}", f"{tmp}/f.o", f"{tmp}/f.elf", f"{tmp}/f.bin")
        Path(src).write_text(c)
        r = subprocess.run([TC / "wibo", MWCC, "-c", *CFLAGS, *flags, src, "-o", obj], capture_output=True, text=True)
        if r.returncode:
            return "compile"
        secs = sections(obj)
        if any(secs.get(s, 0) for s in (".data", ".sdata", ".sbss", ".bss", ".sdata2", ".rdata")):
            return "data"
        if secs.get(".rodata", 0) and rodata is None:
            return "data"
        size = secs.get(".text", 0)
        if not size or size > end - start:
            return "size"
        subprocess.run([sys.executable, ROOT / "tools/set_abi.py", obj], check=True)
        place = [f"--section-start=.rodata=0x{rodata[0]:X}"] if rodata else []
        r = subprocess.run([BIN / "mips64-linux-gnu-ld", "-EL", "-m", "elf32ltsmip", "--no-check-sections",
                            "-nostdlib", "--unresolved-symbols=report-all", "-Ttext", hex(start), *place,
                            "-T", symbol_script_for(c, syms_ld, tmp), "-e", hex(start),
                            obj, "-o", elf], capture_output=True, text=True)
        if r.returncode:
            return "link"
        subprocess.run([BIN / "mips64-linux-gnu-objcopy", "-O", "binary", "-j", ".text", elf, out], check=True)
        mine = Path(out).read_bytes()
        table = None
        if rodata:
            subprocess.run([BIN / "mips64-linux-gnu-objcopy", "-O", "binary", "-j", ".rodata", elf, out],
                           check=True)
            table = Path(out).read_bytes()
    if out_bytes is not None:
        out_bytes.update(text=mine, rodata=table)
    if mine != orig[:len(mine)] or any(orig[len(mine):]):
        return "mismatch"
    # a short object is padded by `. = ALIGN(., 16)` in the linker script
    if len(mine) != end - start and (start + len(mine) + 15) // 16 * 16 != end:
        return "padding"
    # the code is right, so the case addresses are: a wrong table is a wrong range
    if rodata and table != rodata[1]:
        return "rodata"
    return "match"


def try_function(job):
    binary, name, start, end, asm, syms_ld, orig, rodata = job
    if "jtbl" in asm and rodata is None:
        return name, None, "jumptable"  # a table the data disassembly doesn't have
    if ALABEL.search(asm):
        # `alabel` marks a global entry point inside the body: other code calls
        # that address, and a C file cannot name a point in the middle of one of
        # its functions, so this range cannot become one file (the callers would
        # lose their target when the label goes away)
        return name, None, "entry inside"
    def check(c, flags=()):
        return verify(c, start, end, syms_ld, orig, flags, rodata=rodata)

    # the reason logged is the closest any draft came, not the last draft's:
    # one draft that fails to link must not hide another that only mismatches
    rank = ["mismatch", "padding", "rodata", "size", "data", "link", "compile", "m2c"]
    why = "m2c"
    mismatched = []
    uncompiled = []
    for kind, c in candidates(name, with_jump_tables(binary, asm) if rodata else asm):
        r = check(c)
        why = min(why, r, key=lambda x: rank.index(x) if x in rank else -1)
        if r == "match":
            return name, (kind, c, ()), f"match_{kind}"
        if r in ("mismatch", "size", "padding", "rodata"):
            mismatched.append((kind, c))
        elif r == "compile":
            uncompiled.append(c)
    # some files may have been built with other optimization settings
    for flags in (("-O4",), ("-O2",)):
        for kind, c in mismatched:
            if check(c, flags) == "match":
                return name, (kind, c, flags), f"match_{kind}{flags[0]}"
    if uncompiled:
        from repair import repair  # imports us: only import it when needed
        # repair the plainest draft first: the structified and swapped variants
        # are derived from it, and a repair inserts casts where m2c's types are
        plain = sorted(set(uncompiled),
                       key=lambda s: ("typedef struct" in s, SWAP_CMP.sub(r"\3 \2 \1", s) != s))
        for source in plain[:2]:
            c = repair(source)
            if not c:
                continue
            variants = [c]
            swapped = SWAP_CMP.sub(r"\3 \2 \1", c)
            if swapped != c:
                variants.append(swapped)
            for variant in variants:
                if check(variant) == "match":
                    return name, ("repair", variant, ()), "match_repair"
                for flags in (("-O2",), ("-O4",)):
                    if check(variant, flags) == "match":
                        return name, ("repair", variant, flags), f"match_repair{flags[0]}"
            # it compiles now but the bytes differ: hand it to the permuter, which
            # searches source orders for exactly this kind of difference
            saved = ROOT / "build" / "repair" / binary / f"{name}.c"
            saved.parent.mkdir(parents=True, exist_ok=True)
            saved.write_text(c)
            return name, None, "repaired"
    return name, None, why


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--jobs", type=int, default=max(1, (os.cpu_count() or 2) - 2))
    ap.add_argument("--limit", type=int)
    ap.add_argument("--only")
    ap.add_argument("--skip", type=int, default=0, help="skip the first N candidate functions")
    ap.add_argument("--retry", help="only functions whose last result was one of these (comma-separated)")
    ap.add_argument("--dry-run", action="store_true", help="report, don't write src files")
    ap.add_argument("--jumptables", action="store_true", help="only functions that use a jump table")
    a = ap.parse_args()

    base = VRAM.get(a.bin, 0x45ECC0)
    data = (ROOT / "extract" / f"{a.bin}.bin").read_bytes()
    srcdir = ROOT / "src" / a.bin
    done = {p.stem for p in srcdir.rglob("*.c*")} if srcdir.exists() else set()
    funcs = [f for f in functions(a.bin)
             if (a.bin != "SLES_539.74" or region_prefix(f[1]) == "game") and f[0] not in done
             and (not a.only or f[0] == a.only)]
    if a.retry:
        tsv = ROOT / "build" / f"autodecomp_{a.bin}.tsv"
        last = dict(l.split("\t", 1) for l in tsv.read_text().splitlines()) if tsv.exists() else {}
        want = set(a.retry.split(","))
        funcs = [f for f in funcs if last.get(f[0]) in want]
    if a.jumptables:
        funcs = [f for f in funcs if JTBL_REF.search(f[3])]
    funcs = funcs[a.skip:]
    if a.limit:
        funcs = funcs[:a.limit]

    syms_ld = ROOT / "build" / f"{a.bin}_all_syms.ld"
    syms_ld.parent.mkdir(exist_ok=True)
    symbol_script(a.bin, syms_ld)
    jobs, tables = [], {}
    for n, s, e, asm, _ in funcs:
        try:
            tables[n] = rodata_range(a.bin, asm)
        except KeyError:
            tables[n] = None
        ro = tables[n] and (tables[n][0], data[tables[n][0] - base:tables[n][1] - base])
        jobs.append((a.bin, n, s, e, asm, syms_ld, data[s - base:e - base], ro))

    stats = {}
    ranges = {n: (s, e) for n, s, e, _, _ in funcs}
    log = open(ROOT / "build" / f"autodecomp_{a.bin}.tsv", "a")
    with Pool(a.jobs) as pool:
        for i, (name, c, why) in enumerate(pool.imap_unordered(try_function, jobs, chunksize=4), 1):
            stats[why] = stats.get(why, 0) + 1
            log.write(f"{name}\t{why}\n")
            if c and not a.dry_run:
                kind, c, flags = c
                s, e = ranges[name]
                if flags:
                    c = f"// flags: {' '.join(flags)}\n" + c
                if tables[name]:
                    c = f"// rodata: 0x{tables[name][0]:X} 0x{tables[name][1]:X}\n" + c
                note ={"m2c": "m2c draft",
                        "repair": "m2c draft, with the casts CodeWarrior asks for",
                        "asm": "asm function (hand-written VU0 code; m2c can't express it)"}[kind]
                # asm functions carry the original instructions verbatim: they go in
                # asmfunc/, which .gitignore keeps out of the repository
                dest = srcdir / "asmfunc" if kind == "asm" else srcdir
                dest.mkdir(parents=True, exist_ok=True)
                (dest / f"{name}.c").write_text(f"// range: 0x{s:X} 0x{e:X}\n// auto: {note}, verified byte-exact\n" + c)
            if i % 250 == 0 or i == len(jobs):
                print(f"{i}/{len(jobs)} " + " ".join(f"{k}={v}" for k, v in sorted(stats.items())), flush=True)


if __name__ == "__main__":
    main()
