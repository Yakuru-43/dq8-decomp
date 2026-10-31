// CLASS reorder+register score=12 (172 vs 172 B) — the C below; re-run 2026-10-31 factory-2.
// Sections are now RIGHT (gp/absolute mixup from the earlier note is fixed): plain
// externs for D_003E0A98/D_003E0A9C (like matched src/SLES_539.74/func_00228120.c),
// .data attribute only on the 0x415xxx symbols. ROM +004 is lw $a3,%gp_rel(A9C)($gp)
// and +024 lw $t0,%lo(EF4)($v1): mine now agrees on both forms.
// Remaining diff is the first 0x48 bytes only: ROM loads A9C at +004 into $a3 and
// the -1 into $a2 at +00C (the F78 store keeps $a2 for the F7C base reuse at +028),
// constant 3 in $v1 (+03C, reusing v1 from the F84 lui), then the EF4 value in $t0
// stores to F7C in the delay slot (+044). Mine schedules the -1 first into $a1,
// A9C into $t0 at +014, EF4 into $a3, and 3 into $a1; the F7C/F80 stores land on
// +038/+044 with different base regs. Tried: direct globals, locals read at top,
// loads as separate statements between the stores — all three fold to IDENTICAL
// output (scheduler normalizes). #pragma optimization_level 4 is worse (136 B,
// loads merged). permute.py unusable in this worktree (.toolchain/permuter/ empty,
// no cpp in PATH) — retry there with the permuter, this is pure register/schedule.
// Structure confirmed: three independent ifs (==3 plain beq, ==4/==5 beql), then-
// blocks cold with b back to the NEXT test, tail F84 = F84 + A98 (a0/a1, b + ds sw).
// range: 0x228920 0x2289D0
#include "common.h"

extern s32 D_003E0A98;
extern s32 D_003E0A9C;
extern s32 D_00415EF4 __attribute__((section(".data")));
extern s32 D_00415F70 __attribute__((section(".data")));
extern s32 D_00415F74 __attribute__((section(".data")));
extern s32 D_00415F78 __attribute__((section(".data")));
extern s32 D_00415F7C __attribute__((section(".data")));
extern s32 D_00415F80 __attribute__((section(".data")));
extern s32 D_00415F84 __attribute__((section(".data")));

void func_00228920(s32 arg0) {
    D_00415F70 = arg0;
    D_00415F74 = 0;
    D_00415F78 = -1;
    D_00415F80 = D_003E0A9C;
    D_00415F84 = 0;
    D_00415F7C = D_00415EF4;
    if (arg0 == 3) {
        D_00415F84 = 0x37;
    }
    if (arg0 == 4) {
        D_00415F84 = 0x3C;
    }
    if (arg0 == 5) {
        D_00415F84 = 0x41;
    }
    D_00415F84 = D_00415F84 + D_003E0A98;
}
