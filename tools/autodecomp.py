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
ANY_LABEL = re.compile(r"^(?:glabel|dlabel|jlabel|alabel) (\w+)\n\s+/\* \w+ ([0-9A-F]{8}) ", re.M)
INSN_ADDR = re.compile(r"^\s+/\* \w+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", re.M)
HILO = re.compile(r"%(?:hi|lo)\((\w+)")
GPREL = re.compile(r"%gp_rel\((\w+)")
EXTERN = re.compile(r"^extern (.+?) (\w+)(\[\])?;", re.M)


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
    if re.search(r"\b(sp[0-9A-F]+|subroutine_arg\d+)\b", c) and not re.search(r"\b[su](8|16|32|64) sp[0-9A-F]+;", c):
        return None  # m2c lost track of the stack
    return c


def fix_externs(c, asm):
    hilo, gprel = set(HILO.findall(asm)), set(GPREL.findall(asm))

    def repl(m):
        typ, sym, arr = m.group(1), m.group(2), m.group(3) or ""
        if sym in hilo and not arr:
            return f'extern {typ} {sym} __attribute__((section(".data")));'
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
        for v in [x for b in bases for x in (b, SWAP_CMP.sub(r"\3 \2 \1", b))]:
            if v not in seen:
                seen.add(v)
                yield "m2c", v
    if VU0.search(asm):
        c = asm_function(name, asm)
        if c:
            yield "asm", c


def verify(c, start, end, syms_ld, orig, flags=()):
    """'match' if `c` compiles to exactly the original bytes, else the failure reason."""
    with tempfile.TemporaryDirectory() as tmp:
        src, obj, elf, out = (f"{tmp}/f.c", f"{tmp}/f.o", f"{tmp}/f.elf", f"{tmp}/f.bin")
        Path(src).write_text(c)
        r = subprocess.run([TC / "wibo", MWCC, "-c", *CFLAGS, *flags, src, "-o", obj], capture_output=True, text=True)
        if r.returncode:
            return "compile"
        secs = sections(obj)
        if any(secs.get(s, 0) for s in (".data", ".rodata", ".sdata", ".sbss", ".bss", ".sdata2", ".rdata")):
            return "data"
        size = secs.get(".text", 0)
        if not size or size > end - start:
            return "size"
        subprocess.run([sys.executable, ROOT / "tools/set_abi.py", obj], check=True)
        r = subprocess.run([BIN / "mips64-linux-gnu-ld", "-EL", "-m", "elf32ltsmip", "--no-check-sections",
                            "-nostdlib", "--unresolved-symbols=report-all", "-Ttext", hex(start),
                            "-T", syms_ld, "-e", hex(start), obj, "-o", elf], capture_output=True, text=True)
        if r.returncode:
            return "link"
        subprocess.run([BIN / "mips64-linux-gnu-objcopy", "-O", "binary", "-j", ".text", elf, out], check=True)
        mine = Path(out).read_bytes()
    if mine != orig[:len(mine)] or any(orig[len(mine):]):
        return "mismatch"
    # a short object is padded by `. = ALIGN(., 16)` in the linker script
    if len(mine) != end - start and (start + len(mine) + 15) // 16 * 16 != end:
        return "padding"
    return "match"


def try_function(job):
    binary, name, start, end, asm, syms_ld, orig = job
    if "jtbl" in asm:
        return name, None, "jumptable"
    why = "m2c"
    mismatched = []
    uncompiled = []
    for kind, c in candidates(name, asm):
        why = verify(c, start, end, syms_ld, orig)
        if why == "match":
            return name, (kind, c, ()), f"match_{kind}"
        if why in ("mismatch", "size", "padding"):
            mismatched.append((kind, c))
        elif why == "compile":
            uncompiled.append(c)
    # some files may have been built with other optimization settings
    for flags in (("-O4",), ("-O2",)):
        for kind, c in mismatched:
            if verify(c, start, end, syms_ld, orig, flags) == "match":
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
                if verify(variant, start, end, syms_ld, orig) == "match":
                    return name, ("repair", variant, ()), "match_repair"
                for flags in (("-O2",), ("-O4",)):
                    if verify(variant, start, end, syms_ld, orig, flags) == "match":
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
    a = ap.parse_args()

    base = VRAM.get(a.bin, 0x45EC80)
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
    funcs = funcs[a.skip:]
    if a.limit:
        funcs = funcs[:a.limit]

    syms_ld = ROOT / "build" / f"{a.bin}_all_syms.ld"
    syms_ld.parent.mkdir(exist_ok=True)
    symbol_script(a.bin, syms_ld)
    jobs = [(a.bin, n, s, e, asm, syms_ld, data[s - base:e - base]) for n, s, e, asm, _ in funcs]

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
                note = {"m2c": "m2c draft",
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
