# Idioms

Techniques that matched functions the Qwen factory had given up on. The nightly Opus
batch adds one entry per technique (newest last), and every factory session reads this
file before its first attempt and checks the function's asm against the signs.

Entry format:

    ## <short name>
    Sign: what the asm, or Qwen's try_match diff, shows.
    Fix: what to write (C, a type, a compiler flag) and how to try it.
    Example: src/<bin>/<file>.c
    Solved: func_... (date, who)

## divbyzerocheck: a divide guarded by bnez + break 0, 7
Sign: `bnez <divisor>` before `div $zero, a, b` and `break 0, 7` after it, around a `/` or
`%`, and no C rewrite produces the guard (Qwen's notes call it the "div-guard family").
Fix: write the plain `/` or `%`; the guard comes from a compiler flag. Try it with
`tools/try_match.py <file> <func> <vram> --show -- -O3 -flag divbyzerocheck`; on a match
put `// flags: -flag divbyzerocheck` on line 2, under `// range:` (verify.py and the
build read it there).
Example: src/SLES_539.74/func_002FF0D0.c
Solved: func_002FF0D0 func_00301200 func_003012F0 func_00301350 func_00302140
func_0020C5C0 func_00210C90 func_00210F80 func_00212BA0 (2026-10-24, Opus)

## jumptable: a switch compiled to a jump table (queue blocker `jumptable`)
Sign: `lui/addiu %hi/%lo(jtbl_XXXXXXXX)`, `sll`, `addu`, `lw`, `jr` after an
`sltiu $at, x, N` range check. The table lives in the data segment.
Fix: write a plain `switch`. Run `tools/jtbl.py <func> [--bin <bin>] --m2c`: it prints
the `// rodata: 0xSTART 0xEND` line and an m2c draft that has the `switch` (plain m2c
cannot see the table). Put the rodata line on line 2, under `// range:`; verify.py then
checks the table too (`RODATA` = the code matches but the table range is wrong), and the
build links the file's .rodata at START. Table tips: an entry that points at the code
after the switch is a `case X: break;` (the table's first and last entries are always
real cases, so look at both ends: `addiu v, v, -LOW` / `sltiu N` give LOW..LOW+N-1);
a separate `b join` stub with no code is a case that assigns the value the variable
already holds (`case 1: id = 0x81A; break;`); case bodies come out in source order;
a constant subtracted in pieces before the table base (`addiu -0x8000; addiu -0x7A00;
addiu -0xD6`) means the source switched on `x - 0xFA00`. `p = alloc(); if (p) p =
ctor(p);` gives `bnel`; the original's `beqz`/`nop` shape is `obj->f = p != 0 ? ctor(p) : p;`.
If your switch compiles to a compare chain (`addiu v1, CASE; beq`) where the original
has a table, list the empty cases too (`case -11: ... case -4: case -1: break;`): the
compiler only builds a table when enough values are cases. `try_match` cannot see
tables: when verify.py says RODATA, `tools/jtbl.py <func> --diff <src>` prints the
entries you send elsewhere (each is usually a missing `case N: break;`).
Range tests near switches: `x >= -0x13 && x <= -0xB` gives `slti v1, -0x13 / slti at,
-0xA` (the `$at` one); `x < -0xA` gives `v1` for both.
Not solved yet: a switch inside an inlined bool helper (func_0035F030 family: an extra
`andi 0xFF`), and an `if (x == 0) { switch }` whose switch block CodeWarrior placed after
the code that follows it (func_0026D230 family).
Example: src/SLES_539.74/func_00357EF0.c, src/BATTLE/func_004601B0.c
Solved: func_002C70D0 func_0035F200 func_002148E0 func_0036D030 func_00357EF0
func_002F7830 func_002F8B50 func_0020E1A0 func_004601B0 (BATTLE), CASINO func_0045ED10, and autodecomp:
func_001FA430 func_00327620 func_003276A0 (2026-10-25, Opus)

## fptodp: a float passed to an unprototyped function (queue blocker `hilo`, `link`)
Sign: verify.py says LINK; the linker reports `undefined reference to 'fptodp'` (or
another soft-float helper); the m2c draft declares a callee as `T func_X();` and passes
it a float expression.
Fix: C promotes a float argument of an unprototyped function to double. Give the callee
a full prototype (`f32 func_0013BCA0(f32);`, `void func_0010AF10(f32, f32 *, f32 *);`).
autodecomp now tries this itself (`float_protos`). Then the usual work: m2c's `sp30` /
`sp70` slots are arrays (a 4x4 `f32 mtx[16]`, an `f32 vec[4]`; declaration order sets
their offsets), and a pointer that m2c shows as `x + 8`, `x + 0x10` is a cursor
over 8-byte records: `args++; f(args++); g(args);`.
Example: src/SLES_539.74/func_001EFB20.c, src/SLES_539.74/func_001EB0B0.c
Solved: func_001EFB20 func_001EB0B0 (2026-10-25, Opus)
