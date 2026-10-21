#!/usr/bin/env python3
"""Match tail-call thunks: functions that are `j target` plus delay-slot setup.

m2c drafts these as `jal` + `return v0`, which compiles to different bytes;
the original source is `return target(...)` (a tail call). This tool recognises
the shape, generates a few candidate C expressions for the delay slot, and
keeps only what autodecomp.verify() calls byte-exact.

    thunkify.py [--bin SLES_539.74] [--dry-run] [--list]

Results are appended to build/autodecomp_<bin>.tsv as `match_thunk` so
permute_batch skips them. Afterwards: `make split && make -j`.
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import autodecomp as a  # noqa: E402

ROOT = a.ROOT
INSN = re.compile(r"/\* \w+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(\S.*)")
REG = re.compile(r"^\$(\w+)$")
ARG = re.compile(r"^\$a([0-3])$")

LOAD_TYPE = {"lw": "s32", "lwu": "u32", "lh": "s16", "lhu": "u16", "lb": "s8", "lbu": "u8",
             "ld": "s64", "lq": "s128", "lwc1": "float", "ldc1": "double"}


def parse_imm(s):
    s = s.strip()
    return int(s, 0)


def is_imm(s):
    try:
        int(s.strip().lstrip("+-"), 0)
        return True
    except ValueError:
        return False


def disasm_ops(asm_text):
    """[(mnemonic, [operands])] for the function body, nops dropped."""
    ops = []
    for m in INSN.finditer(asm_text):
        text = m.group(3).split("/*")[0].split("#")[0].strip()
        if not text or text.split()[0] == "nop":
            continue
        parts = text.split(None, 1)
        ops.append((parts[0], [p.strip() for p in parts[1].split(",")] if len(parts) > 1 else []))
    return ops


def arg_expr(idx):
    return f"arg{idx}"


class Gen:
    """Builds candidate sources for one tail-jump function."""

    def __init__(self, name, target, slot):
        self.name, self.target, self.slot = name, target, slot
        self.nparams = 0  # params arg0..arg(nparams-1) are declared
        self.floats = set()  # param indices typed float (f12..)

    def need(self, idx):
        self.nparams = max(self.nparams, idx + 1)

    def call(self, over=None):
        """target(arg0, ..., argN-1) with over[i] replacing arg i."""
        over = over or {}
        args = [over.get(i, arg_expr(i)) for i in range(self.nparams)]
        return f"return {self.target}({', '.join(args)});"

    def params(self):
        ps = []
        for i in range(self.nparams):
            t = "float" if i in self.floats else "void *"
            ps.append(f"{t} {arg_expr(i)}")
        return ", ".join(ps) or "void"

    def emit(self, body, extern=None):
        ext = extern or f"extern int {self.target}();"
        return (
            '#include "common.h"\n\n'
            f"{ext}\n\n"
            f"int {self.name}({self.params()}) {{\n{body}\n}}\n"
        )


def candidates(name, target, slot):
    """Yield C sources to try for `j target` with one delay-slot instruction."""
    if not slot:  # pure tail call
        g = Gen(name, target, slot)
        yield g.emit("    " + g.call())
        return
    if len(slot) > 1:
        return
    mn, ops = slot[0]

    def reg(i):
        m = REG.match(ops[i]) if i < len(ops) else None
        return m.group(1) if m else None

    # addiu $aX, $aX, IMM  /  addiu $aX, $aY, IMM : pointer offset
    if mn in ("addiu", "addu") and len(ops) == 3:
        dx, sy = ARG.match(ops[0]), ARG.match(ops[1])
        if dx and sy and (mn == "addu" or is_imm(ops[2])):
            x, y = int(dx.group(1)), int(sy.group(1))
            imm = parse_imm(ops[2]) if mn == "addiu" else None
            g = Gen(name, target, slot)
            g.need(max(x, y))
            if mn == "addu" and reg(2) == "zero":
                yield g.emit("    " + g.call({x: f"arg{y}"}))
                return
            if imm is None:
                return
            off = f"(char *)arg{y} + 0x{imm:X}" if imm >= 0 else f"(char *)arg{y} - 0x{-imm:X}"
            g2 = Gen(name, target, slot)
            g2.need(max(x, y))
            yield g2.emit("    " + g2.call({x: off}))
            if imm == 0:
                g3 = Gen(name, target, slot)
                g3.need(max(x, y))
                yield g3.emit("    " + g3.call({x: f"arg{y}"}))
            return

    # addiu $aX, $zero, IMM : constant argument
    if mn == "addiu" and len(ops) == 3 and ARG.match(ops[0]) and reg(1) == "zero" and is_imm(ops[2]):
        x = int(ARG.match(ops[0]).group(1))
        imm = parse_imm(ops[2])
        g = Gen(name, target, slot)
        g.need(x)
        yield g.emit("    " + g.call({x: str(imm) if -2**31 <= imm < 2**31 else f"0x{imm:X}u"}))
        return

    # daddu $aX, $zero, $zero : null pointer argument
    if mn == "daddu" and len(ops) == 3 and ARG.match(ops[0]) and reg(1) == "zero" and reg(2) == "zero":
        x = int(ARG.match(ops[0]).group(1))
        g = Gen(name, target, slot)
        g.need(x)
        yield g.emit("    " + g.call({x: "(void *)0"}))
        g2 = Gen(name, target, slot)
        g2.need(x)
        yield g2.emit("    " + g2.call({x: "0"}))
        return

    # daddu $aX, $aY, $zero : pass another argument through
    if mn == "daddu" and len(ops) == 3 and ARG.match(ops[0]) and ARG.match(ops[1]) and reg(2) == "zero":
        x, y = int(ARG.match(ops[0]).group(1)), int(ARG.match(ops[1]).group(1))
        g = Gen(name, target, slot)
        g.need(max(x, y))
        yield g.emit("    " + g.call({x: f"arg{y}"}))
        return

    # lw/lh/... $aX, off($aY) : load an argument through a pointer
    if mn in LOAD_TYPE and len(ops) == 2:
        m = re.match(r"^(-?0x[0-9A-Fa-f]+|\d+)\((\$\w+)\)$", ops[1])
        dx, dy = ARG.match(ops[0]), (ARG.match(m.group(2)) if m else None)
        if dx and dy:
            x, y = int(dx.group(1)), int(dy.group(1))
            off = parse_imm(m.group(1))
            soff = f"+ 0x{off:X}" if off >= 0 else f"- 0x{-off:X}"
            g = Gen(name, target, slot)
            g.need(max(x, y))
            yield g.emit("    " + g.call({x: f"*({LOAD_TYPE[mn]} *)((char *)arg{y} {soff})"}))
            return

    # sw/sb $zero|$aY, off($aX) : store side effect, then tail call
    if mn in ("sw", "sb", "sh") and len(ops) == 2:
        m = re.match(r"^(-?0x[0-9A-Fa-f]+|\d+)\((\$\w+)\)$", ops[1])
        dx = ARG.match(m.group(2)) if m else None
        dv = ARG.match(ops[0]) if reg(0) not in ("zero",) else None
        if dx and (reg(0) == "zero" or dv):
            x = int(dx.group(1))
            off = parse_imm(m.group(1))
            ty = {"sw": "s32", "sh": "s16", "sb": "u8"}[mn]
            val = "0" if reg(0) == "zero" else f"arg{int(dv.group(1))}"
            soff = f"+ 0x{off:X}" if off >= 0 else f"- 0x{-off:X}"
            for vol in ("volatile ", ""):
                g = Gen(name, target, slot)
                g.need(max(x, int(dv.group(1)) if dv else 0))
                store = f"*({vol}{ty} *)((char *)arg{x} {soff}) = {val};"
                yield g.emit(f"    {store}\n    " + g.call())
            return

    # lw $aX, %gp_rel(D)($gp) : argument from a global
    if mn in LOAD_TYPE and len(ops) == 2:
        m = re.match(r"^%gp_rel\((\w+)\)\(\$gp\)$", ops[1])
        dx = ARG.match(ops[0])
        if m and dx:
            x, glob = int(dx.group(1)), m.group(1)
            g = Gen(name, target, slot)
            g.need(x)
            yield g.emit("    " + g.call({x: glob}),
                         extern=f"extern {LOAD_TYPE[mn]} {glob};\nextern int {target}();")
            return

    # sb $zero, %gp_rel(D)($gp) : clear a global, then tail call
    if mn in ("sb", "sw", "sh") and len(ops) == 2:
        m = re.match(r"^%gp_rel\((\w+)\)\(\$gp\)$", ops[1])
        if m and reg(0) == "zero":
            glob, ty = m.group(1), {"sw": "s32", "sh": "s16", "sb": "u8"}[mn]
            g = Gen(name, target, slot)
            yield g.emit(f"    {glob} = 0;\n    " + g.call(),
                         extern=f"extern {ty} {glob};\nextern int {target}();")
            return

    # andi $aX, $aY, IMM : masked argument
    if mn == "andi" and len(ops) == 3 and ARG.match(ops[0]) and ARG.match(ops[1]) and is_imm(ops[2]):
        x, y = int(ARG.match(ops[0]).group(1)), int(ARG.match(ops[1]).group(1))
        imm = parse_imm(ops[2])
        g = Gen(name, target, slot)
        g.need(max(x, y))
        yield g.emit("    " + g.call({x: f"(u32)arg{y} & 0x{imm:X}"}))
        return

    # neg.s $f12, $f12 : negate the float argument
    if mn == "neg.s" and len(ops) == 2 and ops[0] == "$f12" and ops[1] == "$f12":
        g = Gen(name, target, slot)
        g.need(0)
        g.floats = {0}
        yield g.emit("    " + g.call({0: "-arg0"}),
                     extern=f"extern int {target}(float);")
        return

    # swc1 $f12, off($aX) : store the float argument, then tail call
    if mn == "swc1" and len(ops) == 2 and ops[0] == "$f12":
        m = re.match(r"^(-?0x[0-9A-Fa-f]+|\d+)\((\$\w+)\)$", ops[1])
        dx = ARG.match(m.group(2)) if m else None
        if dx:
            x = int(dx.group(1))
            off = parse_imm(m.group(1))
            soff = f"+ 0x{off:X}" if off >= 0 else f"- 0x{-off:X}"
            g = Gen(name, target, slot)
            g.need(max(x, 1))
            g.floats = {1}
            yield g.emit(f"    *(float *)((char *)arg{x} {soff}) = arg1;\n    " + g.call(),
                         extern=f"extern int {target}(void *, float);")
            return


def tail_jump(ops):
    """(setup, target, slot) for straight-line code ending in `j target` (+ slot).

    The jump need not be the first instruction: CodeWarrior schedules argument
    setup before a tail call, and m2c cannot express any of it.
    """
    for i, (mn, o) in enumerate(ops):
        if mn.startswith("b") or mn in ("jr", "jal", "jalr", "ret"):
            return None, None, None
        if mn == "j" and o and re.fullmatch(r"\w+", o[0]):
            if len(ops) - i > 2:
                return None, None, None
            return ops[:i], o[0], ops[i + 1:i + 2]
    return None, None, None


STORE_TYPE = {"sw": "s32", "sh": "s16", "sb": "u8", "sd": "s64", "sq": "s128",
              "swc1": "float", "sdc1": "double"}


def operand_mem(op):
    """(offset, register) or (None, global symbol) for a memory operand."""
    m = re.match(r"^(-?0x[0-9A-Fa-f]+|\d+)\((\$\w+)\)$", op)
    if m:
        return parse_imm(m.group(1)), m.group(2)
    m = re.match(r"^%gp_rel\((\w+)\)\(\$gp\)$", op)
    if m:
        return None, m.group(1)
    return None, None


def ptr_off(expr, off):
    """`expr` offset by `off` bytes; parenthesised so a `*` cast can wrap it."""
    base = f"(char *) ({expr})"
    return f"{base} + 0x{off:X}" if off >= 0 else f"{base} - 0x{-off:X}"


def apply_insn(mn, ops, regs, stmts, externs, touched):
    """One straight-line instruction into the register map; False if not C."""
    def name(op):
        m = REG.match(op)
        return m.group(1) if m else None

    def src(op):
        m = REG.match(op)
        if not m:
            return op.strip()
        k = m.group(1)
        if k == "zero":
            return "0"
        if re.fullmatch(r"a\d", k):
            touched.add(int(k[1]))  # the function received this argument
        return regs.get(k)

    dst = name(ops[0]) if ops else None
    if dst and re.fullmatch(r"a\d", dst):
        touched.add(int(dst[1]))

    if mn in ("move",) and len(ops) == 2 and dst:
        v = src(ops[1])
        if v is None:
            return False
        regs[dst] = v
        return True

    if mn in ("daddu", "dadd", "addu", "add") and len(ops) == 3 and dst:
        s, t = src(ops[1]), src(ops[2])
        if s is None or t is None:
            return False
        if t == "0":
            regs[dst] = s
        elif s == "0":
            regs[dst] = t
        else:
            return False  # a real sum, not an argument shuffle
        return True

    if mn == "or" and len(ops) == 3 and dst and src(ops[2]) == "0":
        v = src(ops[1])
        if v is None:
            return False
        regs[dst] = v
        return True

    if mn in ("addiu", "daddiu", "ori", "li") and dst and is_imm(ops[-1]):
        # from $zero (or `li`) this is a constant argument; otherwise an offset
        base = src(ops[1]) if len(ops) == 3 else "0"
        if base is None:
            return False
        if base != "0":
            if mn == "ori":
                regs[dst] = f"(u32) {base} | 0x{parse_imm(ops[-1]):X}"
            else:
                regs[dst] = ptr_off(base, parse_imm(ops[-1]))
        else:
            regs[dst] = str(parse_imm(ops[-1]))
        return True

    if mn == "andi" and len(ops) == 3 and dst and is_imm(ops[2]):
        v = src(ops[1])
        if v is None:
            return False
        regs[dst] = f"(u32) {v} & 0x{parse_imm(ops[2]):X}"
        return True

    if mn in LOAD_TYPE and len(ops) == 2 and dst:
        off, base = operand_mem(ops[1])
        if base is None:
            return False
        if off is None:  # a global
            externs.append(f"extern {LOAD_TYPE[mn]} {base};")
            regs[dst] = base
        else:
            v = src(base)
            if v is None:
                return False
            regs[dst] = f"*({LOAD_TYPE[mn]} *) ({ptr_off(v, off)})"
        return True

    if mn in STORE_TYPE and len(ops) == 2:
        off, base = operand_mem(ops[1])
        v = src(ops[0])
        if base is None or v is None:
            return False
        ty = STORE_TYPE[mn]
        if off is None:
            externs.append(f"extern {ty} {base};")
            stmts.append(f"{base} = {v};")
        else:
            b = src(base)
            if b is None:
                return False
            stmts.append(f"*({ty} *) ({ptr_off(b, off)}) = {v};")
        return True

    if mn == "neg.s" and len(ops) == 2 and dst:
        v = src(ops[1])
        if v is None:
            return False
        regs[dst] = f"-({v})"
        return True

    return False


def walk_source(name, target, body):
    """C for `setup... ; j target` : argument shuffles and stores, then a tail call."""
    regs = {f"a{i}": f"arg{i}" for i in range(4)}
    stmts, externs, touched = [], [], set()
    for mn, ops in body:
        if not apply_insn(mn, ops, regs, stmts, externs, touched):
            return None
    arg_regs = {int(m.group(1)) for r in regs if (m := re.fullmatch(r"a(\d)", r))}
    n = max(arg_regs | touched, default=-1) + 1
    args = [regs.get(f"a{i}", f"arg{i}") for i in range(n)]
    params = ", ".join(f"void *arg{i}" for i in range(n)) or "void"
    seen, ext = set(), []
    for e in externs + [f"extern int {target}();"]:
        if e not in seen:
            seen.add(e)
            ext.append(e)
    return ('#include "common.h"\n\n' + "".join(e + "\n" for e in ext) +
            f"\nint {name}({params}) {{\n" +
            "".join(f"    {s}\n" for s in stmts) +
            f"    return {target}({', '.join(args)});\n}}\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--bin", default="SLES_539.74")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--list", action="store_true", help="only list recognised thunks")
    a_ = ap.parse_args()

    base = a.VRAM.get(a_.bin, 0x45ECC0)
    data = (ROOT / "extract" / f"{a_.bin}.bin").read_bytes()
    srcdir = ROOT / "src" / a_.bin
    done = {p.stem for p in srcdir.rglob("*.c*")} if srcdir.exists() else set()
    funcs = [f for f in a.functions(a_.bin)
             if (a_.bin != "SLES_539.74" or a.region_prefix(f[1]) == "game") and f[0] not in done]

    syms_ld = ROOT / "build" / f"{a_.bin}_all_syms.ld"
    syms_ld.parent.mkdir(exist_ok=True)
    a.symbol_script(a_.bin, syms_ld)

    found = kept = 0
    log = open(ROOT / "build" / f"autodecomp_{a_.bin}.tsv", "a")
    for name, s, e, asm_text, _ in funcs:
        ops = disasm_ops(asm_text)
        setup, target, slot = tail_jump(ops)
        if not target:
            continue
        found += 1
        if a_.list:
            print(f"{name} 0x{s:X} -> {target} "
                  f"[{' ; '.join(m + ' ' + ','.join(o) for m, o in setup + slot)}]")
            continue
        matched = None
        tries = ([c for c in candidates(name, target, slot)] if not setup
                 else [walk_source(name, target, setup + slot)])
        tries = [c for c in tries if c]  # a body we cannot express in C
        for c in tries:
            if a.verify(c, s, e, syms_ld, data[s - base:e - base]) == "match":
                matched = c
                break
        if matched:
            kept += 1
            log.write(f"{name}\tmatch_thunk\n")
            log.flush()
            if not a_.dry_run:
                srcdir.mkdir(exist_ok=True)
                (srcdir / f"{name}.c").write_text(
                    f"// range: 0x{s:X} 0x{e:X}\n// auto: tail-call thunk, verified byte-exact\n" + matched)
            print(f"MATCH {name} -> {target}")
    log.close()
    print(f"{a_.bin}: {found} tail-jump shapes, {kept} matched")


if __name__ == "__main__":
    main()
