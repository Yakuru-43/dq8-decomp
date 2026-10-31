// CLASS structural score=32 (31 words differ, 176 vs 172 bytes)  [best of 3 attempts]
// func_0021C6B0, 176 B, asm/SLES_539.74/game_21BCD0.s (line 745). Session cut at
// 45 min after attempt 3; row left as todo, NOT stuck. Progress: score 41 -> 39 -> 32.
//
// Shape (decoded): 6-arg function, arg4 in $t0, arg5 in $t1 (EE args 5-6; see
// idioms-new/func_00221B60.md). Dispatch tests arg4 == 8 / 0x10 / 0x20 (all beq,
// forward, then default b; daddu v1,a0,zero in the FIRST beq's delay slot = end=arg0
// live on every path). case 8: header word 0x6E000000|((a1|0xC000)|(a2<<16)) stored
// at (u32*)arg0 (sw in the b-to-loop-check delay slot); base=arg0+4 kept in $a1 via
// `addiu $a1,$v1,0x4` -> SOURCE OPERAND IS THE end LOCAL (base = end + 4, not arg0+4;
// attempt with arg0+4 gave addiu $a1,$a0,0x4); dst=(u32*)base into $t0 (daddu t0,a1);
// bottom-test while (arg2 > 0) with lhu v0,0(t1) in the bgtzl delay slot, body
// a2--, idx<<=2, t1+=2, lw a3[idx], sw (dst), dst+=4 - body already byte-exact;
// tail: q = (dst-base)/4 signed bgez/sra pattern, end = base + q*4, return
// (end - arg0)/4 (second bgez/sra pattern). 0x10/0x20/default all return (a0-a0)/4.
//
// Attempt history:
//  1. if/else-if, no 0x10/0x20 tests -> score 41: CW dropped empty else-ifs (no
//     beqs emitted) and inlined case body first (bne, not beq->forward).
//  2. switch {case 8: body; case 0x10: case 0x20: break;} -> score 39 but CW
//     emitted tests in REVERSE source order (0x20,0x10,8), beql back to body, dst
//     in $v1 (end dead in loop let dst steal $v1), extra daddu v1,a1.
//  3. switch written {case 0x20: case 0x10: break; case 8: body;}, base derived
//     from end, dst = (u32*)(end+4) CSE'd 3x -> score 32, size 176 (4 B too long):
//     first real diff +0x10 = test order came out 8,0x20,0x10 not 8,0x10,0x20
//     (so case-order!=emission-order; try if-chain or swapping 0x10/0x20 source
//     lines next); check register roles after that (want ori into $t0 - freed arg4
//     reg - not $v1, sw in the b delay slot).
// Never committed config lines; verify.py not run (no MATCH yet).
// range-hint 0x21C6B0 0x21C760 (marker defanged so no tool picks it up)
#include "common.h"

s32 func_0021C6B0(s32 arg0, s32 arg1, s32 arg2, u32 *arg3, s32 arg4, u16 *arg5) {
    s32 end;
    u32 *dst;
    s32 idx;

    end = arg0;
    switch (arg4) {
    case 0x20:
    case 0x10:
        break;
    case 8:
        *(u32 *)arg0 = 0x6E000000 | ((arg1 | 0xC000) | (arg2 << 16));
        dst = (u32 *)(end + 4);
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            *dst = arg3[idx];
            dst = dst + 1;
        }
        end = (end + 4) + (((s32)dst - (end + 4)) / 4) * 4;
        break;
    }
    return (end - arg0) / 4;
}
