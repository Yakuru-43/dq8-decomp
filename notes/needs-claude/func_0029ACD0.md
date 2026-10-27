# func_0029ACD0 — needs-claude

CLASS structural score=190 (188 words differ, 844 vs 852 bytes)
(best attempt, `try_match.py ... --show -- -O3`; 2026-10-27 factory-2. The
first diff is only +0x38 (register-only lw dest); everything after +0x2F0 is
block placement + the saved-register cascade — see "The key problem".)

- Asm: `asm/SLES_539.74/game_29A170.s:863`, 864 bytes incl. 3 pad nops
  (real code ends `jr $ra; addiu sp,sp,0x80` at 0x29B020).
- Binary SLES_539.74, TU `dq_monster_ai.cpp`, queue size 864.
- Best C: `notes/needs-claude/func_0029ACD0_best.c` (semantics believed
  complete and byte-exact per offset; guards 1-4 byte-exact now).

## Signature (settled)
`func_0029BB90.c` (matched, in src/) already declares it:
`u8 func_0029ACD0(Ai0029BB90 *ai, s32 index, Unit0029BB90 *unit, s32 arg)` —
BB90 loops `cursor %= 6` over 6 calls until one returns 1, else calls
`func_0029BB00`. So this is "try to activate/assign monster at slot".
Return 1 = handled.

Register map (from prologue + `lh $s2,0x10($s3)`):
`s6=a3=arg`, `s5=a0=ai`, `s4=a1=index`, `s3=a2=unit`, `s2=unit->slot`
(loaded ONCE in the delay slot of the first byte test at 0x29AD18, kept live
across the whole body), `s1=&unit->sub` (`addiu s1,s3,0xE0` in the `bltz`
delay slot at 0x29AD6C), `s0=data` from `func_001FFBA0`. Frame 0x80,
`sd ra,0x70`, `sq` s6..s0.

## Offset/semantic map (all recovered)
Unit (a2): `lh 0x10` slot s16; `sub` at 0xE0. Sub: `s32 state` @0 (0xE0),
`s32 f4` @4, `s32 f8` @8, `s32 fC` @0xC, `s32 f60` @0x60 (word!),
`u8 f70` @0x70, `model` ptr @0x284 (0x364 unit), `data` ptr @0x288 (0x368).
Model*: `u8 f60` @0x60, `u16 list[6]` @0x62, `u8 active[6]` @0x6E.
Data* (`func_001FFBA0(ai,state)` record): `u8 b1` @1, `u8 b2` @2, `u16 fC`
@0xC, `u8 kindF` @0xF, `s32 f20` @0x20. Ai: `u8 mode` @0x3C (==2),
`u8 flags[36]` @0x528 addressed `ai + index + 6*slot`.

Flow (guards, every `return 0` its own stub or a threaded likely-branch; two
`return 1` stubs at 0x29AE9C and 0x29AFA4):
1. `unit == 0` → 0 (sq s0 in the beqz delay slot).
2. `slot = unit->slot` (lh into s2, in the beqz delay slot of 3);
   `model->active[index] != 0` → need `ai->flags[6*slot+index] != 0` else 0.
3. `unit->sub.state = model->list[index]` (lhu); `unit->sub.f4 = index`;
   `sub = &unit->sub;` THEN `unit->sub.state < 0` → 0 (dead but emitted;
   `&sub` materialises in that bltz's delay slot); `>= 0x2BA` → 0;
   `== 0` → `func_0029BB00(ai, unit); return 1`.
   All three tests + the FFBA0 call must read `unit->sub.state` — one
   `lw $a1,0xE0($s3)` feeds the bltz, the slti, the second beql and the
   call's a1 (no reloads).
4. `data = func_001FFBA0(ai, unit->sub.state)`; `sub->data = data` @0x288;
   `sub->f8 = data->b1` (lbu→a0→sw), `sub->fC = data->b2`.
5. `if (ai->mode == 2 || sub->f70 == 3) { if (b1!=3 && kindF!=0x35 &&
   kindF!=0x36) return 0; }` (mode==2 branches forward into the check block).
6. `bits = data->f20` (lw in the bne delay slot); `if (sub->state == 0x1A8)
   bits |= 0x20000000`; gate `(bits & 0x20000000) != 0 || (data->fC > 0 &&
   data->fC < 0x32)` (lhu, `blez` skip + `slti 0x32/beqz`) → body:
   `if (sub->f60 >= 2) return 0;` (emitted `slti 2; beql at,0`),
   `if (sub->model != 0 && sub->model->f60 == 2) return 0;`.
7. `if (arg != 0 && data->kindF == 0x37) return 0;`.
8. `if (func_0035DE00(unit) == 1)` (s8 → dsll32/dsra32 24) `{ if (
   func_0035E590(unit) == 0) { if (kindF == 0x35 || kindF == 0x36)
   return 0; } }`.
9. `if (func_0035F200(D_00456E30) != 0) { if (func_0035F0C0(D_00456E30)
   != 0) { if (kindF == 0x35 || kindF == 0x36) return 0; } }` — both entry
   paths into the tail block 0x29AF08 (`bnez →0x29AFAC` / `beqz →0x29AF08`,
   and the kind checks at 0x29AFC0 re-enter 0x29AF08 via `bne`; NOT a loop).
   `D_00456E30` is `extern char D_00456E30[];` and passed WITHOUT `&`
   (`&D_...` gives `char (*)[]` → mwcc error).
10. tail: `k = sub->model->f60`; `if (k != 0) { if (k == 2) { if
    (func_0029A960(ai,unit) == 0) return 0; } else if (k == 1) { if
    (func_0029AA30(ai,unit) == 0) return 0; } }` — both calls test
    `andi 0xFF` + bnez→0x29AF70 (u8 returns; the 0x29AA30 block is placed
    BEFORE the 0x29A960 block despite k==2 tested first).
11. `if (func_0029AC20(ai, unit, sub->model->f60) == 0) return 0;` (u8, andi
    0xFF, beql→ret0; a1=unit in the jal delay slot, a2 from a fresh
    `lw 0x284; lbu 0x60` pair).
12. `if (sub->model->active[index] != 0) { ai->flags[6*slot+index] = 0; }
    return 1;` — reads offset **0x6E** (`lw 0x284(s1); addu s4; lbu 0x6E`) —
    active[index] again, NOT a reset field (earlier note/draft said reset
    @0x528: wrong, the asm loads 0x6E). The flag-store address is REBUILT
    from `s2` (slot): `sll v0,s2,1` in the `bnel` delay slot at 0x29AFA0,
    then `addu s2; sll 1; addu s5; addu s4; b→return1-stub; sb zero,0x528`.

## The key problem (why score 190)
Four independent leftovers, all after the guards:
1. **slot/sub register swap**: the original keeps `slot` in $s2 and `sub` in
   $s1; my best C gets slot=$s1, sub=$s2 — CW then recomputes the reset
   address from the wrong saved reg pair (frame cascade). Tried declaring
   `[sub,data,slot]` and `[slot,sub,data]`: no swap. Def order (slot first
   both times) doesn't drive it either. Untested leads: `s16 slot` instead
   of `s32`; a separate `u8 *flag = &ai->flags[6 * slot];` local feeding both
   uses (the original adds ai BEFORE index, mine hoists `index+ai` into $v1
   — see 3); a `.cpp` rewrite; permute.py once the rest is register-only.
2. **+0x38 lw dest**: `lw $a0,0x364($s3)` vs `lw $v0` — pure allocation of
   the model temp in the active[] address calc.
3. **6*slot reassociation** (both flag-address sites): original
   `sll,addu s2,sll,addu s5,addu s4` = 6slot → +ai → +index; mine folds
   `index+ai` first into a $v1 temp. Writing the address as
   `(&ai->flags[6 * slot])[index]`-style two-step may pin it.
4. **Tail block order**: AA30's call block before A960's; try `switch`, or
   swapping the arms with a different guard shape.

## What was tried
Session 2026-10-27 (factory-2, 5 attempts, score 205 → 190):
1. Hoisted `slot = unit->slot;` to just after the null check — fixes the
   s2 lifetime (matches +0x48 delay-slot load once s2 is allocated right).
2. `unit->sub.state` (not `sub->state`) in the three guards and the
   `func_001FFBA0` call — single `lw $a1,0xE0($s3)`, then `bltz $a1`,
   `slti/beql`, `beql $a1` and the a1 call arg all byte-exact (was two
   loads, one via $s1/$s2).
3. `sub = &unit->sub;` placed between `f4 = index` and the `< 0` guard —
   the `addiu` is then pulled into the bltz delay slot and the branch stays
   a plain `bltz` to the shared stub (with the def lower, CW threads
   `bltzl` + `daddu v0,zero` and the shape diverges).
4. Dropped the phantom `reset` field (step 12 reads `active[index]` 0x6E).
   `extern char D_00456E30[];` passed by name.

## Risks / notes for the fixer
- `func_0029AC20` (PMF-call, itself LINK on `__ptmf_scall`) can be CALLED
  from this file: `tools/autodecomp.py` `ADDR_SYM` auto-defines every
  `func_[0-9A-F]{8}` referenced by the C at its own address — no symbol_addrs
  alias needed (the earlier "verify needs the AC20 label" claim was wrong).
- Step 3's dead `bltz state` guard: keep it, CW emitted it.
- `data->fC > 0 && < 0x32` on a u16: `blez`-skip then `slti/beqz` (best.c
  hits this layout already).
- The BB90 sibling (`func_0029BB90.c`) matched with `s32 i; s32 *cursor;`
  declaration order — here the analogous trick did NOT swap slot/sub, the
  allocator seems driven by something else for the three locals.
