// range: 0x307460 0x3074F0
#include "common.h"

extern s16 D_003D00D0[];
extern s16 D_003D00D2[];

s32 func_00307460(s32 arg0, f32 fparg0) {
    s32 i;

    if (18.0f <= fparg0 || fparg0 <= 6.0f) {
        for (i = 0; D_003D00D0[i] >= 0; i += 2) {
            if (arg0 == D_003D00D0[i]) {
                return D_003D00D2[i];
            }
        }
    }
    return arg0;
}
