# func_0020BFE0 — needs-claude

- Binary: SLES_539.74, size 288 bytes, no blocker, no jumptable.
- Asm: `asm/SLES_539.74/game_20B770.s`, `glabel func_0020BFE0`.

## What it does

`(void f(char *arg0, f32 arg1))`. An object with a count at +0x5874 and an
entry array at `arg0 + i * 0xC0 + 0x5610` (stride 192). Sequence:

1. `E(count)->f10 = arg1` (ternary: `count < 0` yields null pointer, then
   dereferenced anyway — same shape as matched `func_0020BF90`).
2. Fresh load of count; `E(i)->f18 = E(i)->f18` (the load is in the delay
   slot of the second ternary's `bgez`; one `lw` feeds both ternaries).
3. `v = (s32)((f32)E->i14 * f18 * E->f10 * E->f1C)` (`mul.s` chain, left
   associativity matches, `cvt.w.s`); `if (v >= 0x80) v = 0x7F;`
   (`slti $at,$a2,0x80` + `bnez` + `addiu 0x7F`).
4. Fresh load of count; `q = count < 0 ? 0 : arg0 + i * 0x6C + 0x5790`
   (stride 108, strength-reduced `sll/subu/sll`); `if (q)` (beqz + nop)
   `func_00372520(q, (f32)v / 127.0f)` (`lui 0x42FE` = 127.0f, `div.s`).

Three `lw $a1, 0x5874($a0)` in the original: one per group; the two loads
are NOT common-subexpression'd with each other (each uses the immediate
form `0x5874($a0)`).

## The blocker

My C gets the whole function instruction-exact **except** one extra
instruction at +0xC: CodeWarrior CSEs the address `arg0 + 0x5874`, puts
`addiu $a2, $a0, 0x5874` in the first block's branch delay slot (displacing
`sll $v1, $a1, 1`, turning `bgezl` into `bgez` + one-instruction shift for
the rest of the function), and reuses it for the second/third `lw`
(`lw $a1, 0($a2)`). The original materialises the address per load, never
hoists it. Everything after +0x34 is then one slot off.

## What was tried

- Ternary `p = idx < 0 ? 0 : arg0 + idx * 0xC0 + 0x5610` with one shared
  `idx` local, separate `idx1`/`idx2` locals, struct member access via
  `typedef struct { char pad[0x5874]; s32 count; } Owner` — all CSE'd.
- if/else instead of ternary for the second group (matches blocks 2/3 once
  the store is between the loads, but block 1 still gets the hoist).
- `((s32 *)arg0)[0x5874 / 4]` spelling — normalised, CSE'd.
- `// flags: -O2` — much worse (extra `nop`s, `bgez` + `nop`).

The C that is closest (all other groups byte-exact; kept out of `src/`
because it does not match), diff `try_match.py ... --show`: single real
diff `DIFF at +0xC: mine 04A10003 orig 04A30003` (rest is the +4 shift):

```c
// range: 0x20BFE0 0x20C100
#include "common.h"

void func_00372520(char *, f32);                     /* extern */

typedef struct {
    char pad[0x5874];
    s32 count;
} Owner;

void func_0020BFE0(char *arg0, f32 arg1) {
    s32 idx1;
    s32 idx2;
    char *p;
    char *q;
    f32 t18;
    s32 v;

    idx1 = ((Owner *)arg0)->count;
    p = idx1 < 0 ? 0 : arg0 + idx1 * 0xC0 + 0x5610;
    M2C_FIELD(p, f32 *, 0x10) = arg1;

    idx2 = ((Owner *)arg0)->count;
    p = idx2 < 0 ? 0 : arg0 + idx2 * 0xC0 + 0x5610;
    t18 = M2C_FIELD(p, f32 *, 0x18);
    p = idx2 < 0 ? 0 : arg0 + idx2 * 0xC0 + 0x5610;
    M2C_FIELD(p, f32 *, 0x18) = t18;

    v = (s32)((f32)M2C_FIELD(p, s32 *, 0x14) * t18
              * M2C_FIELD(p, f32 *, 0x10) * M2C_FIELD(p, f32 *, 0x1C));
    if (v >= 0x80) {
        v = 0x7F;
    }

    idx2 = ((Owner *)arg0)->count;
    q = idx2 < 0 ? 0 : arg0 + idx2 * 0x6C + 0x5790;
    if (q != 0) {
        func_00372520(q, (f32)v / 127.0f);
    }
}
```

Probably needs an idiom that prevents the address CSE (a barrier between
the loads? the original may not read `0x5874` as an `arg0`-relative
expression in all three places, or the function may be C++ with the entry
lookup in a non-inlined-ish member).
