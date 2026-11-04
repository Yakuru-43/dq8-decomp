CLASS structural score=93 (92 words differ, 424 vs 420 bytes)

func_0035ABD0, 432 bytes, SLES_539.74, range 0x35ABD0 0x35AD80 (asm in
game_359CF0.s). Triple-nested search over a 32-entry array of 0x590-byte
entries: outer `pass = 1..2`, middle `kind = 0x80..0x8F`, inner `i = 0..31`.
limit = func_0035F5B0(); ret = -1. Inner loop: e = arg0 + i*0x590; skip if
*(s32*)e <= 0 or lh(e+0xC) != kind; if pass == 1 then sel = 0, break (its own
stub: a0=0 in the beql delay slot, no `best = 0`); else
func_00201760(e, 0) > 0 / !(e->0x568 < limit) / lbu e+0x554 / +0x555 / +0x557
all branch to ONE shared cold stub `daddu a0,zero,zero; b merge; daddu
s2,zero,zero` (all five gotos share it); else sel = 1 (`daddiu a0,zero,1` in
the beql delay slot), best = e if best == 0 (cold block falls into the
increment) or e->0x568 < best->0x568. Merge: beql a0 -> kind-increment; then
if best != 0: ret = kind, func_0035C640(best, 1), byte 0x560 = 1, byte 0x557
= 1 (second store in the `b` delay slot), and break the kind loop. After the
kind loop: `if (ret < 0x80) continue; if (ret < 0x90) break;` and one shared
return stub `b epi; daddu v0, s5, zero`.

Best C: notes/needs-claude/func_0035ABD0.c.draft (kept in the worktree, NOT
committed). Registers/struct/loops all right: with decl order
`limit, ret, pass, kind, best, i, e, sel` the saved allocation came out
e=$s0, i=$s1, best=$s2, kind=$s3, pass=$s4, ret=$s5, arg0=$s6, limit=$s7
(MH2 Saved: reverse of declaration order). Struct Entry matches
src/SLES_539.74/func_00359CF0.c's (count@0, pad0[8], kind@0xC s16, u8s at
0x554/0x555/0x557/0x560, prio@0x568) — first try had pad0[0xC] which shifted
every field by 4 (0x564/0x55B stores). `goto none;` (not six inline
`best = 0; break;` arms) is what merged the five guards into one cold stub —
same trick as notes/idioms-new/func_00272830.md.

Remaining diff (one word at +0x38, shifts all 90 after): orig enters the
outer loop as `addiu $s4,$zero,1; slti $at,$s4,3; beqz $at,<exit>; nop;
b <kind-test>; addiu $s3,$zero,0x80` — test at top, `at` register, forward
beqz. Mine emits `b <bottom test>; addiu $s4,$zero,1; b <kind cond>; ...`,
i.e. the outer for is ROTATED (test bottom, bnez back) and one word longer.
The two inner loops are byte-identical to the orig from +0x58 on.

Tried (3 attempts, then the 45-min session clock):
1. per-arm inline fail stores -> 7 duplicated zero stores, CLASS structural
   107.
2. shared `goto none` stub -> merged stub, score 93 (registers still swapped
   to s0=best/s1=e/s2=i).
3. MH2 Loops "A loop rotated, or not" (line 3279): `while` and `for` with an
   init ARE rotated, `for (; c; inc)` keeps the test at top -> changed outer
   to `pass = 1; for (; pass < 3; pass++)` — still rotated (score 93). Not
   tried yet: `for (;;) { if (pass >= 3) break; ... }`;
   `#pragma opt_rotateloops off` around just this function (MH2 says it
   fixed AveTcp_Send's outer loop); `if (pass < 3) do { } while (pass < 3);`
   (idioms.md line 179 "Loop with a top guard and the body inline"); the
   sibling note notes/needs-claude/func_0035A0C0.c.draft has the same outer
   shape with the same one-extra-`b` symptom — the two should be solved
   together.

MH2 entries read: Index (offset 87), Loops section (3279).
