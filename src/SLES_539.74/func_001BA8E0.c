// range: 0x1BA8E0 0x1BA940
#include "common.h"

extern s32 D_00411E78[];

s32 func_001BA8E0(char *arg0) {
    s32 idx;
    s32 val;

    if (*(s32 *)(arg0 + 0) == 1) {
        idx = (s32)*(f32 *)(arg0 + 4);
    } else {
        idx = *(s32 *)(arg0 + 4);
    }

    val = D_00411E78[idx];

    if (*(s32 *)(arg0 + 8) == 3) {
        *(s32 *)(*(char **)(arg0 + 0xC) + 4) = val;
    }

    return 1;
}
