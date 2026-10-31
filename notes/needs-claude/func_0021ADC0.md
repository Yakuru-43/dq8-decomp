# func_0021ADC0 — CLASS reorder+register score=2 (2 words differ, 196 vs 196 bytes); really 1 word: the slt dest at +0x74 (the other is the masked `%gp_rel(D_003E098C)` load)

Size: 208 B (`0x21ADC0`–`0x21AE90`). `void func_0021ADC0(void)`.

## What it does
- `obj = func_0020D7F0(func_0020D660())` — the arg setup `daddu a0,v0` sits in the
  `jal func_0020D7F0` delay slot (arg-in-delay-slot form, cf. idioms-new 5th-arg note);
  `count = 0` (s1) scheduled into the first call's delay slot.
- `if (obj != 0) count = obj->0x10;` (beqz+nop+lw shape).
- `per = (func_0020D6E0(0) + 0x3FF) / 0x400;` — the `addiu 0x3FF / bgez / sra 10 /
  addiu 0x3FF / sra 10` block is CodeWarrior's signed `/0x400` after a `+0x3FF` bias.
  `a0 = 0` for the call is itself in that `jal`'s delay slot.
- Loop 30x over `D_003E098C[i]` (80-byte stride: `sll 2, addu, sll 4`):
  if `slot->0x0 == 0` (byte is **s8**: `lb`, not `lbu` — verified):
  - `count < per`: `slot->0x12 = obj->0x8 != 0` — emitted as `sb a0(1)` in the
    `bnel` delay slot, then `lw v1,8(s0); bnez` skip / `b` + `sb zero` in its delay;
  - else: `slot->0x12 = 0; count -= per;`.

## Best C
`notes/needs-claude/func_0021ADC0_best.c` (untracked). Structs local to the file,
per-file externs (`func_0020D7F0` is `char *(char *)` elsewhere, here typed on the
obj struct; codegen identical).

## The one remaining word (+0x74)
```
mine:  slt $v1, $s1, $a2 / bnel $v1, $zero, ...
orig:  slt $at, $s1, $a2 / bnel $at, $zero, ...
```
Everything else byte-exact (incl. the `sb a0` with `a0=1` hoisted before the loop —
`addiu a0, zero, 1` at +0x50 — and both delay-slot arg setups).

## What was tried (3 attempts, ~25 min)
1. First draft (guard-clause `continue` form): CLASS structural score=3 — extra
   diff was `lbu` (u8 → fixed to s8, per idioms the byte test is signed here).
2. After s8: reorder+register score=2, only the slt dest word left.
3. Nested `if (slot->field_00 == 0) { ... }` instead of continue: identical bytes
   (score=2), $v1 stays.
- `tools/permute.py` could not run: `FileNotFoundError: 'cpp'` (worktree lacks cpp).
- The $at-vs-$v1 choice likely depends on how the compare value is materialized;
  a candidate to try: a bool-typed local, or letting the comparison appear in a
  context where v1 is still live (the original may keep another value in v1
  elsewhere, forcing $at for the slt). MH2 catalogue entries to check: "an
  argument in t0" / register-selection sections under slt-before-branch.

Qwen, factory-2, 2026-10-31
