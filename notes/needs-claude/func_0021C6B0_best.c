// CLASS reorder+register score=10 (10 words differ, 172 vs 172 bytes)  [best of 6 attempts]
// func_0021C6B0, 176 B, asm/SLES_539.74/game_21BCD0.s (line 745). Session 2026-10-31
// (factory-2) cut at 45 min; row left as todo, NOT stuck. Progress: 41 -> 39 -> 32 -> 34 -> 32 -> 10.
//
// KEY FINDING 2026-10-31: declare `base` as its own s32 LOCAL (`base = end + 4;
// dst = (u32 *)base;`), do NOT repeat (end + 4) three times. That alone: size
// 176 -> 172 exact, test order 8,0x10,0x20 CORRECT, base kept in $a1 across the
// loop, tail bgez/sra blocks byte-exact. All that is left is register roles +
// intra-block order in the case-8 header block (+0x2C..+0x74):
//   * `addiu $a1,$a0,0x4` (mine) vs `addiu $a1,$v1,0x4` (orig): CW copy-propagated
//     end->arg0 in mine; the original reads the end local ($v1, set by the
//     daddu in the first beq's delay slot). Defeating that propagation is THE
//     remaining move; it probably also fixes the roles below (v1 busy with end
//     until +0x34 forces ori/dst elsewhere). MH2 Saved: "A copy the game keeps
//     and yours folds: another type, and a cast in the assignment" - try end as
//     u32 (return then needs the s32 tail: check the tail stays bgez/sra), or a
//     differently-typed arg0.
//   * ori temp $v1 (mine) vs $t0 (orig = arg4's freed register);
//   * header order: mine ori,sll,or,[base],lui,or vs orig ori,lui,[base],sll,or,or
//     (base addiu sits between lui and sll);
//   * dst: mine daddu $v1,$a1,zero in the b's delay slot, sw before the b; orig
//     daddu $t0,$a1,zero before the b, sw $v0,0($a0) in the b's delay slot (+0x48);
//   * loop store/incr on $v1 vs $t0, post-loop `subu $v1,$v1,$a1` vs `subu $v1,$t0,$a1`.
// Everything else matches word-for-word: chain, loop (bgtzl + lhu delay slot),
// both signed /4 blocks, jr ra + nops.
//
// permute.py: `m2c could not draft this function; write base.c by hand` - no m2c
// draft; permute.py always overwrites build/permute/<func>/base.c from m2c
// (tools/permute.py line 41), so hand bases need manual setup of target.o /
// compile.sh / settings.toml per its docstring. Not tried this session.
//
// Switch emission order (MH2 Switches, confirmed twice here): chain = reverse of
// source case order. {case 0x20: case 0x10: break; case 8: body;} emits 8,0x10,0x20.
// (The 2026-10-30 note claiming that order emitted 8,0x20,0x10 was wrong - the
// +0x10 diff then was the beq TARGET off by one word, because the 176-byte build
// placed the join 4 B too low; the addiu constants did match.)
//
// Shape (decoded): 6-arg function, arg4 in $t0, arg5 in $t1 (EE args 5-6; see
// idioms-new/func_00221B60.md). Dispatch tests arg4 == 8 / 0x10 / 0x20 (all beq,
// forward, then default b; daddu v1,a0,zero in the FIRST beq's delay slot = end=arg0
// live on every paths). case 8: header word 0x6E000000|((a1|0xC000)|(a2<<16)) stored
// at (u32*)arg0; bottom-test while (arg2 > 0) with lhu v0,0(t1) in the bgtzl delay
// slot, body a2--, idx<<=2, t1+=2, lw a3[idx], sw (dst), dst+=4; tail:
// q = (dst-base)/4 signed bgez/sra pattern, end = base + q*4, return (end-arg0)/4.
// 0x10/0x20/default all return (a0-a0)/4.
// range-hint 0x21C6B0 0x21C760 (marker defanged so no tool picks it up)
#include "common.h"

s32 func_0021C6B0(s32 arg0, s32 arg1, s32 arg2, u32 *arg3, s32 arg4, u16 *arg5) {
    s32 end;
    s32 base;
    u32 *dst;
    s32 idx;

    end = arg0;
    switch (arg4) {
    case 0x20:
    case 0x10:
        break;
    case 8:
        *(u32 *)arg0 = 0x6E000000 | ((arg1 | 0xC000) | (arg2 << 16));
        base = end + 4;
        dst = (u32 *)base;
        while (arg2 > 0) {
            idx = *arg5;
            arg2 = arg2 - 1;
            arg5 = arg5 + 1;
            *dst = arg3[idx];
            dst = dst + 1;
        }
        end = base + (((s32)dst - base) / 4) * 4;
        break;
    }
    return (end - arg0) / 4;
}
