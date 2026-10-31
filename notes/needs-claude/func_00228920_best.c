// CLASS structural score=37 (attempt 3, bare externs); best attempt 1: reorder+register
// score=12 (172 vs 172 B) with the .data/.sdata attributes below — but mine loads
// D_00415EF4 %gp_rel($gp) and D_003E0A9C via lui+lw, the ROM is the other way round,
// and the prologue store block +000..+044 is scheduled differently.
// Structure is fully right: three independent ifs (==3 plain `beq` with the D_00415F7C =
// D_00415EF4 store in its delay slot, ==4 and ==5 `beql`), all three then-blocks cold
// with `b` back to the NEXT test, tail D_00415F84 = D_00415F84 + D_003E0A98.
// Tried: attempt 1 as below (score 12); attempt 2/3 bare externs for D_00415EF4/A98/A9C
// (score 37 — they link elsewhere, don't use bare externs for these); MH2 catalogue not
// consulted (clock). Needs Claude: fix the gp-vs-absolute classification for
// D_00415EF4 (ROM: %lo($v1)) vs D_003E0A9C (ROM: %gp_rel($gp)) and the prologue order.
// range: 0x228920 0x2289D0
#include "common.h"

extern s32 D_00415EF4 __attribute__((section(".data")));
extern s32 D_00415F70 __attribute__((section(".data")));
extern s32 D_00415F74 __attribute__((section(".data")));
extern s32 D_00415F78 __attribute__((section(".data")));
extern s32 D_00415F7C __attribute__((section(".data")));
extern s32 D_00415F80 __attribute__((section(".data")));
extern s32 D_00415F84 __attribute__((section(".data")));
extern s32 D_003E0A98 __attribute__((section(".sdata")));
extern s32 D_003E0A9C __attribute__((section(".sdata")));

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
