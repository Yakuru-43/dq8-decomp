// range: 0x3074F0 0x307530
#include "common.h"

extern s16 D_003D00D0[];

s32 func_003074F0(s32 arg0) {
    s32 i;

    for (i = 0; D_003D00D0[i] >= 0; i++) {
        if (arg0 == D_003D00D0[i]) {
            return 1;
        }
    }
    return 0;
}
