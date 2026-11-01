CLASS structural score=107 (99 words differ, 400 vs 432 bytes) — first attempt, 2026-11-01, factory-2

# func_0021DFE0 (SLES_539.74, 0x21DFE0, 432 bytes, range 0x21DFE0 0x21E190)

Two-arg search (`s32 func(char *arg0, s32 arg1)`), returns 0/1. My best C:
`notes/needs-claude/func_0021DFE0_best.c`. Frame: orig 0x60 saving ra + s0..s4;
mine came out 0x50 (dropped one s-reg) — the whole block layout diverged
(structural), so this is not a register-allocation case.

## What it does
- Guards: `if (D_003E09DC == 0) return 0; if (arg1 < 2) return 0;`
- `func_00166760(arg0);` (result discarded), then `p = func_00166760(arg0 + 8);`
- `list = D_003E09D4;` — list of 0x14-byte records {count@0, items@4, flag@8};
  `cursor = list->items;` loads **before** the `p != 0` test (asm E03C vs E040).
- Outer loop (bottom test, entry `b` to it): while `index < list->count`:
  `if (cursor->f8 != 0)` [the `lw $a1,0x8($s2)` sits in the back-edge delay
  slot] `if (func_00133F78(p, cursor->f8) == 0) break;` then `index++;
  cursor += 0x14;`. `func_00133F78` arg2 = the same word as the guard.
- If `p == 0`: skip loop, `index = -1` (asm E128: `b <j-test>; addiu $s3,-1`).
- **The puzzle**: normal loop completion (test false) falls through to
  `addiu $s3,$zero,-1` (E070) then `bltz $s3,<nf>` (E074). The break exit
  (E130→E140→E074) does **not** run the -1. So one register is the counter,
  -1 on completion and on p==0, and the found index on break — and there is
  **no** `if (index >= count) index = -1;` test anywhere: no C I tried
  (for-loop + trailing range test, found-flag locals) reproduces
  "unconditional -1 on the fall-through edge, skipped on break" without also
  emitting the range test. Ideas for Claude: CW loop-exit condition
  propagation, a for-loop whose condition or increment the source wrote
  unusually, or the loop + trailing code coming from an inline helper.
- After: `if (index < 0) sub = 0; else if (index >= list->count) sub = 0;
  else sub = list->items + index * 0x14;` (both `sub = 0`s merge into cold
  E148 `b <ret0>; daddu $s3,$zero,$zero`); `if (sub == 0) return 0;` (`beql`
  on a pointer-typed value — see idioms).
- Inner loop identical shape over `sub` {count@0, items@4} of 0x24-byte
  items, guard on `item->f0` (`lw $a1,0($s1)` in the back-edge slot), same
  `func_00133F78(p, item->f0)`, own -1 sentinel (E0DC) and cold `item = 0`
  stub (E168 `b <a0-test>; daddu $a0,$zero,$zero`).
- Found: `D_003E09DC = <reload lw>; D_003E09DC->4 = item; D_003E09DC->0xC =
  sub;` (`sw $s3,0xC($v1)` in the `b <epilogue>` delay slot) and `return 1`
  (`addiu $v0,$zero,1` scheduled before the stores).

## Tried
1 draft (plain guard clauses + two `for` loops + if/else-if found selects,
types as in siblings `src/SLES_539.74/func_0021E340.c` / `func_0021E5F0.c`;
externs `s32 func_00166760(char *)` — matched twin — and
`s32 func_00133F78(s32, s32)`), `try_match -- -O3`: CLASS structural, 400 vs
432 B. Session clock hit the 25-minute-per-function and 45-minute-session
limits immediately after this first attempt (see weekly log), so only one
attempt was made. The 400-vs-432 gap = the missing -1-sentinel block and the
dropped saved register, consistent with the loop shape being wrong rather
than the CSE/RA details.
