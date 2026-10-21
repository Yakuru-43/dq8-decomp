# func_001AD6A0 (SLES_539.74, 0x001AD6A0, 112 bytes) — pilot P14

Bounds-check a slot array, write `val` into `slot->f0`, and if the slot was in
state 4 record `what` and report 1. The first 0x30 bytes come out identical;
**the whole gap is block placement at the tail.**

Original blocks (labels as splat has them):

```
+000  bltz  $a1, EC          /* idx < 0 */
+008  slti  $at, $a1, 0x20
+00C  beqz  $at, EC          /* idx >= 0x20 */
+014  beql  $a3, $zero, E4    + daddu $v0, $zero, $zero
+01C  ... body: sll 4, addiu $v0 = 4, addu, sw $a2, lw $v1
+030  beql  $v1, $v0, E0      + sw $a3, 0xC($a0)
+038  b     F4                + daddu $v0, $zero, $zero
E0:   addiu $v0, $zero, 0x1          /* falls through into the merge */
E4:   b     FC                + nop  /* merge: return result */
EC:   b     FC                + daddu $v0, $zero, $zero   /* guards */
F4:   b     E4                + nop  /* empty else-block */
FC:   jr    $ra               + nop  /* epilogue */
```

Mine (best of six shapes, 92 bytes, everything up to +0x30 identical):

```
+030  beql  $v1, $v0, +0x4C   + sw $a3, 0xC($a0)
+038  daddu $v0, $zero, $zero  /* else-block, falls through into the merge */
+03C  b     +0x54             + nop    /* merge */
+044  b     +0x54             + daddu $v0, $zero, $zero   /* guards */
+04C  b     +0x3C             + addiu $v0, $zero, 0x1     /* then-block */
+054  jr    $ra               + nop
```

Same CFG, one placement difference: in the original the **then**-block falls
through into the merge and the **else**-block survives as its own (empty) block
reached by `b F4`; in mine the else-block is the fall-through, gets merged, and
the then-block jumps back. So I am 20 bytes short with 10 differing lines, and
every one of them is a displacement or one of those two jumps.

Best C (kept out of `src/` so it cannot poison a build:
`build/attempts/func_001AD6A0.c`):

```c
struct Slot { u32 f0; u32 pad[2]; u32 fC; };

s32 func_001AD6A0(struct Slot *slots, s32 idx, u32 val, u32 what) {
    struct Slot *slot;
    s32 result;

    if (idx < 0 || idx >= 0x20) {
        return 0;
    }
    if (what != 0) {
        slot = &slots[idx];
        slot->f0 = val;
        if (slot->f0 == 4) {
            slot->fC = what;
            result = 1;
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }
    return result;
}
```

Tried, all six producing byte-identical output or worse:
1. four separate `return 0` guards → `bltzl`/`beql` with the value in the delay
   slot instead of the shared `EC` block (76 B).
2. `idx < 0 || idx >= 0x20` — **this one is right**: it is what turns the first
   two guards into `bltz`+`nop` / `beqz`+`nop` jumping to a shared block.
3. `if (what == 0) { result = 0; } else { body }` and the mirrored
   `if (what != 0) { body } else { result = 0; }` — identical output, so the
   outer polarity does not matter here.
4. inner `== 4` / `!= 4` — also identical, mwcc normalises it.
5. `s32 result = 0;` at the top with no else — worse (84 B): `result` then lives
   in a register across the body, so the compare moves to `$v1`/`$a0` and the
   branch loses its `l` suffix.

**What would fix it:** what makes mwcc put the *then*-block on the fall-through
into the merge and keep a separate empty block for the else (`b F4; b E4`).
Guesses not tried: an `else` that is an empty compound statement, a `?:` for the
result, or `register` on `result`.

## Retry 2026-10-21 (Claude, pilot-retry session)

The three guesses above were tried and are **ruled out**; the tail is still 10
`*` lines (88–96 B of 112). All new shapes keep the first 0x30 bytes identical.

| shape | diff |
|---|---|
| baseline (best C above) | 92 B |
| outer `else { }` empty compound | 84 B, but `result` left unset on the what==0 path (wrong CFG) |
| `result = 0;` inside the outer body before the inner if (inner has no else; outer keeps its else) | 96 B |
| `register s32 result;` | 92 B (byte-identical to baseline) |
| `.cpp`, `bool result` + `true`/`false` | 92 B (identical) |
| `goto out;` in the else arm / in the then arm | 92 B (identical) |
| then arm written `result = 1; slot->fC = what;` | 92 B (identical) |
| inner `switch (slot->f0) { case 4: … default: … }` | 92 B (identical) |
| nested `switch (what) { case 0 / default }` + inner switch | 92 B (identical) |
| `result = (slot->f0 == 4) ? 1 : 0;` after the store-if | 88 B — but emits `lw; xori 4; sltiu 1` (a bool materialisation the original never has), so `?:` is NOT the source |

Permuter: never actually run by the pilot (pilot.tsv permuter column `no`).
The m2c draft in `build/permute/func_001AD6A0/base.c` does not even compile
(illegal implicit int→struct* on `arg0 + arg1 * 0x10`); hand-fixed base.c to the
best C → `permuter.py --stop-on-zero`: base score 260, **no improvement**, no
`output-*` dirs. Block/jump placement is outside what it permutes.

Exact target (BB order matters): after the inner test `beql v1,v0,E0 + sw a3`:
[else: `b F4; daddu v0,zero,zero`] [then E0: `addiu v0,zero,1`, falls into]
[merge E4: `b FC; nop`] [guard stub EC: `b FC; daddu v0,zero,zero`]
[F4: `b E4; nop`] [FC: `jr ra; nop`]. My output always collapses F4 into E4 and
then places the then-arm last, after the guard stub, jumping backward into the
merge. So the puzzle is one specific mwcc layout decision: the then-arm stays
inline after the else-arm, and the else-arm's join node is *not* unified with
the outer if's join/return stub. Ideas left: an outer `else` that ends in a
`return result;` of its own (two return stubs that then share FC?), a `continue`
over a surrounding construct, the result variable being written once per path by
different means, or something about `$v0` being the compare constant at test time
that lets the scheduler hoist the else's `daddu` out of its own block into the
`b` delay slot, leaving F4 alive. Best C this session: build/retry_p14/s1.c.
