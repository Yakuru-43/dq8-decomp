# func_0047BEA0 — BATTLE, 0x47BEA0..0x47BF70 (200 bytes, frame 0x20)

Best attempt: `CLASS structural score=47 (46 words differ, 196 vs 200 bytes)`
(mine is 196 B: saves s0-s2 only; original saves s0-s3 + ra, frame 0x20).

## What it does
```c
kind = a1->kind;                          // lw $s2, 0x4($a1)
entry = func_359CF0(&D_421AD0, kind);     // s0
r = func_16D5B0(arg0, kind);              // v0, call UNCONDITIONAL
result = 0;                               // daddu s1,zero in call delay slot
if (entry == 0 || r == 0) return 1;       // beql $s0→EPI(addiu v0,1); beql $v0→EPI(addiu v0,1)
entry->active = 0;                        // sb $zero,0x388(s0) in bnez delay slot
if (kind >= 5) {                          // slti at,s2,5; bnez→RET0
    if (kind < 0xA0) {                    // slti at,s2,0xA0; beqz→RET0
        if (entry != 0) {                 // third redundant null test: beqz s0→skip
            result = func_2B02C0(&D_42EAA0, entry->tag);   // s1
        }
        if (result != 0 && result->field4 != 0) {           // lw 0x4(s1); beqz
            func_2C7140(arg0, kind);
        }
    }
}
return 0;                                 // daddu v0,zero at BF48, falls into EPI
```
Returns 1 only on entry==0 || r==0 (both beqls jump straight to the epilogue
with v0=1 in the delay slot); every other path falls through BF48 (v0=0).

## Register mapping (original)
arg0→$s3 (daddu early), kind→$s2 (loaded before the 359CF0 call), entry→$s0,
result→$s1 (saved, although never live across a call). Mine (v3,
`src/BATTLE/func_0047BEA0.cpp`, uncommitted): arg0→$s2, kind→$s1, entry→$s0,
result→$v0 (not saved) — hence the missing 4th `sq`/`lq` and 196 vs 200 B.

## What I tried
1. Plain C `if (entry != 0) { ... }` — gave one beqz+nop, no second test.
2. C++ `if ((entry != 0) != false)` (idioms.md "bool compared with false") —
   got sltu+beqz, not the beql pair; also no v0 re-materialisation.
3. `char *r = func_16D5B0(arg0, kind); if (entry == 0 || r == 0) return 1;` —
   reproduced the two beqls with `addiu v0,1` delay slots and the right call
   position. This is the current best (in the .cpp).
4. Declaration-order swaps for the saved registers (kind/entry/result order,
   with/without the `r` local), per notes/idioms.md "Saved registers follow
   declaration order" and MH2 ref "Saved registers in another order" (line
   344): the original wants arg0 s3 / kind s2 / result s1 / entry s0; none of
   my orders got result into a saved $s1 while keeping the others.
5. `entry->active = 0;` before the kind guards (correct: the sb sits in the
   bnez delay slot so it executes either way).

Remaining diffs beyond the missing s1: the second `beql` delay slot, the
`lw $v1, 0x68`-style reloads are fine; main structural gap is the 4th saved
register (result must be spilled to $s1) and the guard-block scheduling
(sb into the first bnez delay slot).
