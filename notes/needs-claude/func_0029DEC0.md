# CLASS structural score=141 (141/162 words differ; after the last struct fix every
# memory offset is byte-exact — remaining diff is saved-register allocation +
# scan-loop register choice only)

func_0029DEC0, 656 bytes (0x29DEC0–0x29E150), `dq_monster_ai.cpp` slice.
Best C: `notes/needs-claude/func_0029DEC0_best.c` (uncommitted).
Attempts: 4 compiles, ~35 min (session clock cut off the attempt budget).

## What it does
Monster-AI activation. `a0=owner, a1=typeObj (u16 type at +0xC), a2 (arg2), a3 (arg3),
t0 (arg4)` — 5 register args (PS2 ABI, a0–a3+t0).
1. `if (!a1) return;`
2. `target = func_00359CF0(&D_00421AD0, a1->u0C); if (!target) return;`
3. `func_0029DE30(owner, target, 0)` (unlink from owner list at 0x448).
4. scan `owner->nodes[32]` (32-byte slots at 0x48, free when node+0x1C == 0):
   asm computes `base = owner + i*32`, `a0 = base+0x48`, `lw base+0x64`, bottom test
   `i < 0x20` — my loop matches this except register choice.
5. if none: `func_00300CB0(0, &D_003CBEA0, 0x782)` assert, return.
6. zero `target+0x370(b), 0x374(w), 0x150(b), 0x354(w)` in that order; if `lh 0x10 != 0`:
   `target->f364 = func_00298520(owner, target->f00)` (sw in branch delay slot of the
   back-edge to the common head).
7. link node into `owner->head` (0x488) list via node+8/+C; reload of `head->0xC`
   twice in asm (aliasing or thread-shared — a candidate `// thread-shared` spot);
   `val6 = *(u16*)(head+6)` loaded early, `sh`'d into node+6 much later.
8. `key = (lbu 0x10(target) << 8) | lbu 0x12(target)`; sorted walk of `owner->0x448`
   list via f18 (back-link f14), exit when `key == 0xFFFF` or `key < node->u10`
   (`slt/bnez`, 0xFFFF compared with a preloaded `ori`); insert node **before** scan
   (double `lw 0x14(t1)` reload again).
9. node->b0=1,b1=0,b2=0, sh u6, sh key, sw target→0x1C; `target->b56F = arg2`;
   fE0=-1, f140=f144=0, b148=0; `sw 0x200 → 0x354` lands in the **delay slot** of
   `beqz arg3, epilogue`.
10. `kind = target->fD4;` if kind==0 → tail; else if `arg4 != 0 || kind->b60 != 2` →
    respawn block (lock 0035B1B0 with `sw 0→0x354` in its delay slot,
    `func_0029C140(owner,target,1,1)`, unlock, `func_0029E150`); then a **shared tail**
    that re-tests `kind->b60 != 2 → return; arg4 != 0 → return;` (note: when fD4==0
    the original reads address 0x60 — `lbu 0x60($s2)` with s2==0 is genuinely in the
    asm) and writes fE0=-1, f140=0, f144=1, b148=1, 0x354=0.

## What is right
Prologue/epilogue (sp 0x70, sd ra@0x60, sq/lq s0–s5), all field offsets, all stores,
assert, both call sequences, control flow of every block.

## What differs (the 141 words)
Saved-reg map. Original: s0=target(from a1), s1=owner(a0), s2=node, s3=arg4(t0),
s4=arg3, s5=arg2 — prologue copies `a2→s5, a3→s4, t0→s3` first, then `a1→s0` (tested
by the first beqz, `daddu s1,a0` in its delay slot). Mine gets s0=node, s1=target,
s4=owner, s3=arg2, s5=arg3 — CW allocated by first-definition order and my `node = 0`
before the first call steals s0. Per the idiom note on declaration order, try: keep
target's null-check pattern so a1 is "first defined"; delay node's first definition;
or declare locals in order target, owner-copy, ... Assign arg copies explicitly
(`s32 a2c = arg2; ...` in order a2, a3, arg4?) — CW copies pure parameter copies
high-to-low (s5←a2 first). Also my walk loop keeps scan in `$a3`/`$v1` vs original
`$t1`/`$a0` (single reg `$a0` reused for both the `lhu` key and the `lw f18`).
`tools/permute.py func_0029DEC0 --run 600` is the likely finisher once the reg
cascade is right; do NOT take its output blind (per-loop `for (i...)` shape is fine).

## Struct notes
Target layout cross-checks with matched func_0029D5C0.c (fE0, f140, f144, b148, f364).
Node = the Node0029DE30 shape (f8/fC one list, f14/f18 sorted list, f1C backptr) plus
u16 keys at +6/+0x10. Owner: nodes[32] at 0x48 (size 0x20 each), sentinel node at 0x448,
head ptr at 0x488 (head: u16@6, tail ptr @C). Target needs padD8[8] (gap 0xD8–0xE0) and
union {s16 i16; struct{u8 lo;char pad;u8 hi;} b;} at 0x10 (lh vs two lbu).
