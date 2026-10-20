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
