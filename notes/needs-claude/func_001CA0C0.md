# needs-claude: func_001CA0C0

CLASS structural score=48 (48 words differ, 364 vs 364 bytes) — best attempt,
`try_match.py ... --show -- -O3`, 2026-10-29, factory-1.

Size: 368 in the queue (0x1CA0C0..0x1CA230); code ends 0x1CA228+4, so 364
code bytes + padding. `// range: 0x1CA0C0 0x1CA230`.

## What it is
Script-VM helper. `arg0` is a 16-byte tagged pair struct: `{s32 isFloat;
union {s32 i; f32 f} v; s32 tag; union {s32 i; f32 f} w;}` (the
func_001C57D0 `Tagged` shape, twice). Flow:

1. top select `isFloat == 1` → `(s32)f : i` passed as arg to `func_001A2190`
   (if/else form: `bne` + float block + `b join; nop` + separate `lw` else
   block — like func_001B2DC0's top select, not the ternary form);
2. `if (obj == 0) return 0;` — original `beql $s1,$zero,<L214 epi>; daddu
   $v0,$zero,$zero`, mine matches as `void *obj` (idioms.md line-300 rule);
3. `lw $v1, 8(s0)` dispatch, tests `== 2` then `== 0`, then `b <return 1>`:
   case 2 inline (calls `func_002E6BB0(obj, w.i, 0)` then falls into the
   shared `addiu $v0,1` stub), case 0 body inline, default `return 1`. The
   switch idiom (notes/idioms.md line 244) fits: tests in reverse source
   order (`case 0:` first, then `case 2:`, `default:`).
4. **Inside case 0** a second select `lw $v1, 8(s0)` … `bnel $v1,1,+; lw
   $s0,0xC($s0)` + float `lwc1/cvt.w.s/mfc1` falling into the join — a
   ternary `sel = (tag == 1) ? (s32)w.f : w.i;` whose true arm is DEAD (case
   0 means tag==0; tag==1 goes to default `return 1`). CW did not constant
   fold; my draft reproduces the dead arm exactly (ternary idiom,
   notes/idioms-new/func_001C57D0.md).
5. `if (sel == -1)` → out-of-line `jal func_002EA2A0; b <epi>; addiu $v0,1`.
6. `if (BF0(obj)==0 || BE0(obj)<0)` → shared out-of-line block
   (`daddu a0,s1; jal func_002EA2A0; daddu a1,s0; b <v0=1 stub>; nop`) —
   my `||` merged the two failures into one block and gave the original's
   `beqz $v0; nop` + `bltz $v0; nop` (two separate ifs duplicated the block
   and gave `beql` with the arg copy in the delay slot).
7. `r = func_002F0BF0(obj); if (r == 0) return 0;` (`daddu $s2,$v0; beql
   $s2,$zero,<L214>; daddu $v0,$zero,$zero` ✓ mine matches),
   `n = func_002F0BE0(obj); if (n > 0)` (`bgtzl` with `daddu $a0,$s2` delay
   ✓) → `x = func_002F6D60(r, n, sel); if (x == 0) return 0;` →
   `func_002F0BD0(obj, x); x = func_002F0BC0(obj); func_002E72C0(obj, x);
   return 1;` → trailing `return 0`.

## Best C
notes/needs-claude/func_001CA0C0_best.c (also `src/SLES_539.74/` at the time
of the attempt). Cals are declared per-file as in the twin files; obj/r/x
typed `void *`.

## Remaining diffs (the whole 48-word gap is mostly two things)
1. **s0/s1 swapped**: the original keeps the `arg0` pointer in `$s0` (the
   `daddu $s0,$a0,$zero` sits in the top select's `bne` delay slot, and
   `sel` later reuses `$s0` via `lw $s0,0xC($s0)` / `mfc1 $s0`), `obj` in
   `$s1`. Mine gives obj `$s0` and arg0/`sel` `$s1`. I tried reordering the
   declarations (obj first, sel first, obj last) per the SKILL.md
   "saved registers follow declaration order" idiom — all three give the
   same obj→s0/sel→s1/r→s2 allocation; the param-vs-obj choice seems fixed
   by something else (maybe the original had a different local set or an
   explicit pointer local). Every later word then differs only in `$s0`/
   `$s1` register fields.
2. **case 2 exit**: the original *falls through* from the `func_002E6BB0`
   call into the shared `addiu $v0,1; b <epi>; ld $ra` stub (L1A8); mine
   emits a private `b <ld ra>; addiu $v0,1` before the stub (one extra `b`,
   the stub layout then differs: original stub order is
   `addiu; b; ldra`, mine has `b; addiu` then `addiu; b; ldra`).
   Related: idioms.md line 229 ("last arm's else falls straight into
   `jr $ra`") may hint the right spelling.

All branch shapes (beql guard, beql 2 / beql 0 / b-default dispatch, bnel
select with delay-slot lw, beqz+bltz shared-failure pair, bgtzl, beql x==0)
already match; only registers and the case-2 fall-through are left.

## What I tried
- if/else vs ternary for the two selects (top = if/else, inner = ternary):
  confirmed by layout, keep.
- idioms.md entries used: line 244 (switch, reverse case order), line 300
  (void* for `obj == 0` guard → beql), line 105 (shared return stub),
  notes/idioms-new/func_001C57D0.md (ternary select) and
  notes/idioms-new/func_001B2DC0.md (beql guard). mh2 catalogue not needed
  (diff was structural, not instruction-choice).
- 3 attempts, ~25 min, then stopped per session rules.
