CLASS structural score=95 (94 words differ, 520 vs 516 bytes) — from
`tools/try_match.py src/SLES_539.74/func_0019AAB0.c func_0019AAB0 0x19AAB0 --show -- -O3`
(best C in `notes/needs-claude/func_0019AAB0_best.c`, attempt 2; attempt 1 = same minus
the `*(u128 *)pkt1 = *(u128 *)pkt2;` line, score 89 / 512 vs 516).

# func_0019AAB0 (528 B, SLES_539.74) — GS writer, 2x4 quad pushes, 2 attempts

## What it does (analysis confirmed by the diff — everything else MATCHES)
```c
ctx = func_0015F490();
func_0013F240(writer, 6, 0x43, 0, 2);          // 5th arg in $t0, like 19A810
s32 pkt2[4] = {0,0,0,0};                        // inline memset loop @sp+0xC0 — MATCHED ✓
pkt2[0] = func_00145360(ctx) << 4;               // stored in 145330's delay slot ✓
pkt2[1] = func_00145330(ctx) << 4;               // ← THE ONLY WORD-WRONG STORE, see below
s32 pkt1[4] = {0,0,0,0};                         // inline memset loop @sp+0xB0 ✓
s32 pkt0[4] = {0,0,0,0};                         // inline memset loop @sp+0xA0 ✓
for (iy = 0; iy < func_00145450(ctx); iy += 0x40)
    for (ix = 0; ix < func_00145440(ctx); ix += 0x20) {
        *(u128 *)pkt1 = *(u128 *)pkt2;           // lq 0xC0 hoisted to inner-test bnel
                                                  // delay slot, sq $v1,0xB0 in call 1's ✓
        pkt0[0] = iy << 4; pkt0[1] = ix << 4;
        func_0013EFF0(writer, (u128 *)pkt0);     // call 1
        pkt1[0] = pkt0[0] + pkt2[0];             // sums reloaded AFTER the call (callee
        pkt1[1] = pkt0[1] + pkt2[1];             //   writes through the ptr) ✓
        func_0013EFF0(writer, (u128 *)pkt1);     // call 2, [1] store in its delay slot ✓
        pkt0[0] = (iy + 0x40) << 4;              // = s6, hoisted to outer-body entry ✓
        pkt0[1] = (ix + 0x20) << 4;
        func_0013EFF0(writer, (u128 *)pkt0);     // call 3, [0] store in delay slot ✓
        pkt1[0] = pkt0[0] + pkt2[0];
        pkt1[1] = pkt0[1] + pkt2[1];
        func_0013EFF0(writer, (u128 *)pkt1);     // call 4, [0] store in delay slot ✓
    }
func_0013F0E0(writer);
```
The three `= {0,0,0,0}` memsets sit *between* statements: I got them by nesting
`{ s32 pktX[4] = {0,0,0,0}; ... }` scopes (C89 legal, all decls at a block top) —
all three byte loops now come out byte-exact (this was 19A810's open problem #1;
plain `memset()` gave a real `jal`, sibling note). Original registers: s4=ctx, s5=writer,
s3=iy, s2=ix, s1=iy<<4 (outer entry), s6=(iy+0x40)<<4 (bnel delay slot of the outer test),
s0=&pkt0[1], s7=&pkt2[1] (first set after call 1), fp=&pkt1[1].

## Open problem — ONE word
All 94 "differing" words are the cascade of a single shift after +0x88:
- original: `jal 145330; sw $v0,0xC0(sp); sll; addiu $v1,$sp,0xB0; sw $v0,0xC4(sp)`
- mine:     `jal 145330; (nop-less, store EARLY before jal) ... addiu $s0,$sp,0xC4;
  ... sw $v0,0x0($s0)` — CW CSE'd the `&pkt2[1]` address into $s0 for the init store
  (2 words) instead of the original's plain `sw $v0,0xC4($sp)` (1 word). Mine also
  places that store after `addiu $v1,$sp,0xB0` instead of right after the `sll`.
Fix ideas, in order: (1) make pkt2 a `union { u128 q; s32 w[4]; }` (or tag it
`u128`-typed) so `pkt2[1]` stops looking like an addressable array element the
allocator wants to base — the init store may then fold, while the loop's `lw 0($s7)`
stays (original keeps s7=0xC4 for the loop reads only); (2) permute declaration
order (idioms.md "declare them in reverse" / float-temporaries entry); (3) try
`pkt2[1] = ...` written through the u128 union member's word view. Check the
lq/sq copy survives (it matched with the plain `s32[4]` + cast form).
Also verify: `beqz $v1` memset guard delay slot `addiu $v0,$zero,0x10` matched for
all three loops in attempt 2 (loop bodies byte-exact), so don't perturb them.

MH2 catalogue entries consulted: none beyond idioms.md (2 attempts, stopped at the
session cutoff 02:58). Never edited config; nothing staged; src draft deleted,
best C kept here.
