CLASS structural score=236 (161 words differ, 660 vs 360 bytes) — best attempt, two typed views (no union)

# func_0015BDE0

Size 368 (nonmatching 0x168), TU game_15B7A0.s. `void func(void *o, s32 arg1)`,
no prologue, operates on the byte and halfword at `o + 0x40` with RMWs.

## What it does (from asm)

Entry: `lbu $a3,0x40($a0); dsll32/dsrl32 27/29` → mode = bits 2..4 of byte 0x40
(bit-field read). `bnel $v1,zero,LBE88` (branch-likely, delay slot
`addiu $a2,$zero,0x2`).

mode == 0 path: `addiu $v1,2; beq a1→LBE54; addiu $v1,1; beq a1→LBE54;
beql a1,zero→LBE1C; else return`. LBE54 handles arg1==1 and ==2 (two beqs to
ONE block). LBE1C = same block but different constants.

mode != 0 path (LBE88): `beq $a1,$a2(=2) → LBF10; addiu $v1,2;
beql a1,zero-ish chain: beql $a1,$v1→LBEE4 (delay `andi $a1,$v1,1` — DEAD,
a1==2 already branched); beql $a1,$zero→LBEAC (delay `lbu $t0,0x40`); else return`.

Each store block = byte RMW then halfword RMW, both at 0x40($a0):
- byte:  `lbu t0; and ~0x21; or K1; sb`   (K1 = 0x20; in dead LBEE4: `(a3 & ~0x21) | (a1<<5)` where a1 was clobbered to `2&1`=0 in the beql delay slot, and it reuses the ENTRY load $a3, no reload)
- half:  `lhu a2; and ~0x1C1; or K2; sh`
K2 values: LBE54 0x40 (g6=1, daddiu); LBE1C/LBEAC 0x1C0 (materialized `li 7; sll 6`);
LBF10 0x140 (g6=5, daddiu); LBEE4 0x100 (g6=4, daddiu).

So: arg1/mode → {g6,g0}= and {f5,f0}= writes; no-store fallthrough on unmatched arg1.
Bit layout guess: u8 `f0:1, pad:1, mode:3 (bits 2..4), f5:1, pad:2`; u16
`g0:1 (bit 0 — SAME physical bit as f0, written 0 by both RMWs — the
"same bitfield stored twice" idiom, notes/idioms-new/func_00157C00.md),
pad:5, g6:3 (bits 6..8), pad:7`.

## Why stuck

CW (my 3.0.1b151 build) never merges `f0=0; f5=1` into ONE byte RMW
(mask ~0x21|0x20) as the original shows; it emits separate stores and adds
stray `and ~2 | 1` byte RMWs (bits 1..0) — score stuck at structural 236,
my function 660 bytes vs 360. Also mine tests `==2` then `==1` (duplicated
identical arms, two blocks) where the original is two `beq`s to ONE block,
and `arg1==1||arg1==2` folds to a `sltiu` range check. Entry test comes out
`beqz $v1` + nop, original is `bnel $v1,$zero` with `addiu $a2,2` in the
delay slot (a register-allocated constant used by the first compare
`beq $a1,$a2` in LBE88).

## What I tried

1. Union `Flags40 {Byte40 b; Half40 h;}` as member at 0x40 of a pad[0x40]
   struct, `f0=0;f5=1;g0=0;g6=K;` arms → structural 182, RMWs not merged,
   stray stores, 552 B.
2. Same, with duplicated `else if` arms for ==2/==1 → structural 236, 660 B.
3. Two typed views (Obj15BD for byte fields, Obj15BDH cast for halfword),
   no union → structural 236, 660 B (same as 2).
Member addressing `0x40($a0)` is correct in all typed variants.
Best C: `notes/needs-claude/func_0015BDE0_best.c` (uncommitted).

MH2 ref: did not consult (not a near miss; wrong instruction shape from the
start, not a scheduling/register diff).

Questions for Claude: how does the original get ONE merged byte RMW and the
stray-free half RMW? Maybe the fields are declared differently (mode in the
u16 view too?), or CW merges only when writes are separated by the mode
READ, or it's C++ with two classes/references. LBEE4's dead arm (a1==2 after
the beq, body starting `andi $a1,$v1,1` then `f5 = a1`-style) needs a C
spelling that keeps the `beql` + dead test.
