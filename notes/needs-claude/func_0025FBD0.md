CLASS structural score=165 (153 words differ, 616 vs 664 bytes) — best/only attempt, 2026-11-03 factory-2 (session cut off after 1 try; row left todo, budget unused)

# func_0025FBD0 (SLES_539.74, 672 B, asm/SLES_539.74/game_25F6B0.s:357)

Dedup-append into a 4-entry set. Container 0x3D0 = `u32 flag0; u32 pad04; u32 count; items[4]` at +0x10, item 0xF0 B (sibling `func_0025F650.c` scans the same layout; `func_0025FE70` memsets 976 B = 0x10 + 4*0xF0).

Shape:
1. prologue saves `s1=arg0` (sq pair s0@0, s1@0x10, ra@0x20), frame 0x210; stack objects `work`@0x30, `raw`@0x120 (both 0xF0, raw 16-aligned -> head copy is a 15x `lq/sq` loop from `$a1`).
2. `lw v0,8(s1); slti at,v0,4; beqz at,FE0C` -> guard `count >= 4`: `DebugPrintf(D_003C96F8); return 1;` (cold block at FE0C, before the append block).
3. field-wise `work` copy from `raw` with **gaps** (not copied): 0x03, 0x3C-0x3F, 0xC8-0xCF, 0xEC-0xEF. Copied: 3 u8 @0x0; u32 @4,8,0xC; **union re-copy** at 0x10: lh/sh @0x10,0x12,0x14 (u16[3]) **and** lw/sw @0x10,0x14 (u32[2]) — same bytes, both widths; u32 @0x18,0x1C,0x20,0x24,0x28; `u8[16]`@0x2C as 8-iter 2-byte loop (`lb,lb,sb,sb`, counter in $a0); 2x `f32[6]` @0x40,0x58 (12 lwc1/swc1, loads in 6-groups); u32 @0x70,0x74; `u32[16]`@0x80 as 8-iter 8-byte loop; u32 @0xC0,0xC4; u32 @0xD0,0xD4,0xD8,0xDC,0xE0,0xE4; f32 @0xE8. `i = 0` (`daddu s0,zero`) scheduled mid tail-group.
4. scan: `b <test>` (FDE8); test `lw v0,8(s1); slt v0,s0,v0; bnel <body>; sll v0,s0,4`; body `a0=&work; v0 = s1 + (i*16 - i)*16` = &items[i] (`subu/sll 4`), `jal func_00130F38` with `addiu a1,v0,0x10` in the jal delay slot; `beql v0,zero,FDFC; addiu v0,zero,1` (dup=1), else `i++`. Exit path `daddu v0,zero,zero` (dup=0). FDFC `beql v0,zero,FE20; lw v1,8(s1)`.
5. not-dup (FE20): `jal func_00130FD0` `a0 = s1 + count*240 + 0x10`, `a1 = sp+0x120` (**raw**, not work), `a2 = 0xF0`; then `v1 = count+1; sw 0x8(s1); v0=1; sw 0(s1)`; fall to epi, return 1. Dup: `b epi; v0=0` -> return 0.

Best C: `notes/needs-claude/func_0025FBD0_best.c` (attempt 1). What went wrong in attempt 1: frame came out 0x220 with 3 saved regs (`s0,s1,s2` — the copy `for` loops' counter `i` spilled; original keeps only `i` in $s0 and copy counters in $a0/$a1/$a2 temps), and `in = *arg1` (union `Cmd { CmdData d; u128 q[15]; }`) folded to a `jal func_145C00` instead of the inline 15x lq/sq loop. Next: try the head copy as an explicit `u128` for-loop or copy the `q` array member-wise, and check notes/idioms-new/func_00462560.md (pair-wise scratch fills, no struct assignment) for keeping copy counters out of saved regs. mh2 ref entries tried: none yet.
