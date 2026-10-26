# func_0029ACD0 — needs-claude

CLASS structural score=205 (203 words differ, 844 vs 852 bytes)
(best attempt, `try_match.py ... --show -- -O3`; all the churn is from +2F0 on —
block placement + the saved-register cascade, see "Open" below.)

- Asm: `asm/SLES_539.74/game_29A170.s:863`, 864 bytes incl. 3 pad nops
  (real code ends `jr $ra; addiu sp,sp,0x80` at 0x29B020).
- Binary SLES_539.74, TU `dq_monster_ai.cpp`, queue size 864.
- Best C: `notes/needs-claude/func_0029ACD0_best.c` (semantics believed
  complete and byte-exact per offset).

## Signature (settled)
`func_0029BB90.c` (matched, in src/) already declares it:
`u8 func_0029ACD0(Ai0029BB90 *ai, s32 index, Unit0029BB90 *unit, s32 arg)` —
BB90 loops `cursor %= 6` over 6 calls until one returns 1, else calls
`func_0029BB00`. So this is "try to activate/assign monster at slot: pick an
entry from the group list"; return 1 = handled.

Register map (from prologue + `lh $s2,0x10($s3)`):
`s5=a0=ai`, `s4=a1=index`, `s3=a2=unit`, `s6=a3=arg`, `s2=unit->slot`
(loaded ONCE, in the delay slot of the first byte test at 0x29AD18, kept in a
register across the whole body — see Open), `s1=&unit->sub` (`addiu s1,s3,0xE0`
in the `bltz` delay slot), `s0=` data ptr from `func_001FFBA0`.
Frame 0x80, `sd ra,0x70`, `sq` s6..s0.

## Offset/semantic map (all recovered)
Unit (a2): `lh 0x10` slot s16; `sub` at 0xE0. Sub: `s32 state` @0 (0xE0),
`s32 f4` @4 (0xE4), `s32 f8` @8, `s32 fC` @0xC, `s32 f60` @0x60 (word!),
`u8 f70` @0x70, `model` ptr @0x284 (0x364 unit), `data` ptr @0x288 (0x368).
Model* (points at ai+6*slot, cf. flags below): `u8 f60`, `u16 list[6]` @0x62,
`u8 active[6]` @0x6E, `u8 reset[6]` @0x528. Data* (`func_001FFBA0(ai,state)`
record): `u8 b1` @1, `u8 b2` @2, `u16 fC` @0xC, `u8 kindF` @0xF, `s32 f20`
@0x20. Ai: `u8 mode` @0x3C (==2), `u8 flags[36]` @0x528 addressed
`ai + index + 6*slot` (= model+index+0x528, same address).

Flow (guards, every `return 0` its own stub; two `return 1` stubs at 0x29AE9C
and 0x29AFA4):
1. `unit == 0` → 0 (sq s0 in the beqz delay slot).
2. `model->active[index] != 0` → need `ai->flags[6*slot+index] != 0` else 0.
3. `sub->state = model->list[index]` (lhu); `sub->f4 = index`;
   `state < 0` → 0 (dead but emitted); `&sub` materialised in that bltz's
   delay slot; `state >= 0x2BA` → 0; `state == 0` → `func_0029BB00(ai,unit);
   return 1` (a0=s5 in the beql delay slot).
4. `data = func_001FFBA0(ai, state)` (a1 = the loaded state, not reloaded);
   `sub->data = data` @0x288; `addiu v1,2` already here for step 5's compare;
   `sub->f8 = data->b1` (lbu→a0→sw), `sub->fC = data->b2`.
5. `if (ai->mode == 2 || sub->f70 == 3) { if (b1!=3 && kindF!=0x35 &&
   kindF!=0x36) return 0; }` — layout: `beq mode,2 →0x29ADC4`,
   `bne f70,3 →0x29ADF8`, three `beq → 0x29ADF8`, fallthrough `b→ret0`.
6. `bits = data->f20` (lw in the bne delay slot); `if (sub->state == 0x1A8)
   bits |= 0x20000000`; gate
   `(bits & 0x20000000) != 0 || (data->fC > 0 && data->fC < 0x32)` (lhu,
   `blez` skip + `slti 0x32/beqz`) → body: `if (sub->f60 >= 2) return 0;`
   (emitted `slti 2; beql at,0`), `if (sub->model != 0 && sub->model->f60 == 2)
   return 0;`.
7. `if (arg != 0 && data->kindF == 0x37) return 0;`.
8. `if (func_0035DE00(unit) == 1)` (s8 → dsll32/dsra32 24) `{ if (
   func_0035E590(unit) == 0) { if (kindF == 0x35 || kindF == 0x36)
   return 0; } }`.
9. `if (func_0035F200(&D_00456E30) != 0) { if (func_0035F0C0(&D_00456E30)
   != 0) { if (kindF == 0x35 || kindF == 0x36) return 0; } }` — both entry
   paths into the tail block 0x29AF08 (`bnez →0x29AFAC` / `beqz →0x29AF08`,
   and the kind checks at 0x29AFC0 re-enter 0x29AF08 via `bne`; NOT a loop).
10. tail: `k = sub->model->f60`; `if (k != 0) { if (k == 2) { if
    (func_0029A960(ai,unit) == 0) return 0; } else if (k == 1) { if
    (func_0029AA30(ai,unit) == 0) return 0; } }` — both calls test
    `andi 0xFF` + bnez→0x29AF70 (so u8 returns; 0x29AA30 block is placed
    BEFORE the 0x29A960 block despite k==2 tested first).
11. `if (func_0029AC20(ai, unit, sub->model->f60) == 0) return 0;` (u8, andi
    0xFF, beql→ret0; a1=unit in the jal delay slot, a2 from a fresh
    `lw 0x284; lbu 0x60` pair).
12. `if (model[index + 0x528] != 0) { ai->flags[6*slot+index] = 0; }
    return 1;` — the reset address is REBUILT from `s2` (slot):
    `sll/daddu-s2` in the `bnel` delay slot at 0x29AFA0, then
    `addu s2; sll 1; addu s5; addu s4; b→return1-stub; sb zero,0x528`.

## The key problem (why score 205)
CW keeps `slot` in **$s2 across the entire function** (saved in prologue,
`lq $s2` in epilogue, single `lh 0x10($s3)` at entry). My draft's `slot` local
is only assigned inside the step-2 branch, so CW re-loads `lh $v1,0x10($s3)`
after the AC20 call and recomputes the reset address from a temp +
`addu $a0,$s4,$s5` (frame 0x70, s6 not saved). Write it so ONE `s32 slot`
assignment (before/at the step-2 test) feeds both the step-2 check and the
step-12 reset, and `arg` survives as $s6 — the saved-reg cascade
(ra@0x70, s6@0x60, s5@0x50 … s0@0x0) then lands by itself.
Declaration-order idiom applies (BB90 precedent).

## What was tried
1. One attempt (draft above): guards + if/else-if chains per the idioms
   (guard clauses, shared return stubs, beql-with-a0-copy pattern). Score 205,
   everything from +0x2F0 displaced +8..+12 words + frame/register cascade.
2. Not pursued (session clock): hoisting `slot` (above); `switch` vs if/else
   for the step-10 kind dispatch; `permute.py` not run (structural, not
   register-only).

## Risks / notes for the fixer
- `func_0029AC20` is a PMF-call function (see func_0029AC20.md) whose link is
  still blocked (`__ptmf_scall`); calling it from a new src file is fine for
  try_match (relocation masked) but `verify.py` needs the label — this file
  should be matched together with / after AC20's alias lands.
- Step 3's dead `bltz state` guard: keep it, CW emitted it.
- `data->fC > 0 && < 0x32` on a u16: `blez`-skip then `slti/beqz` (draft hit
  this layout already).
