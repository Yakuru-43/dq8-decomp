// best attempt for func_004790B0 (needs-claude, see func_004790B0.md)
// range: 0x4790B0 0x4791B0
// CLASS reorder+register score=28
#include "common.h"

extern M2C_UNK D_00480620 __attribute__((section(".data")));
extern M2C_UNK D_0047D170 __attribute__((section(".data")));
extern M2C_UNK D_0047E130 __attribute__((section(".data")));
extern M2C_UNK D_00480720 __attribute__((section(".data")));
extern s32 D_003E1904 __attribute__((section(".sdata")));
extern s32 func_132D38(void);

void func_004790B0(void) {
    s32 i;
    s32 r;
    s32 j;
    s32 *dst;
    s32 *src;

    for (i = 0; i < 3; i++) {
        r = func_132D38() % 21;
        dst = (s32 *)&D_00480620 + 21 * i;
        src = (s32 *)&D_0047D170 + 63 * D_003E1904 + 21 * i;
        for (j = 0; j < 21; j++) {
            if (++r >= 21) {
                r = 0;
            }
            dst[j] = src[r];
        }
    }
    src = (s32 *)&D_0047E130 + 8 * D_003E1904;
    for (r = 0; r < 8; r++) {
        ((s32 *)&D_00480720)[r] = src[r];
    }
}
