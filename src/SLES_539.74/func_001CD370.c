// range: 0x1CD370 0x1CD3F0
#include "common.h"

extern s32 D_00412150[];

s32 func_001CD370(char *arg0) {
    s32 idx;
    s32 val;

    if (*(s32 *)(arg0 + 0) == 1) {
        idx = (s32)*(f32 *)(arg0 + 4);
    } else {
        idx = *(s32 *)(arg0 + 4);
    }

    if (idx >= 0 && idx < 0x20) {
        val = D_00412150[idx];
    } else {
        val = -1;
    }

    if (val < 0) {
        return 0;
    }

    if (*(s32 *)(arg0 + 8) == 3) {
        *(s32 *)(*(char **)(arg0 + 0xC) + 4) = val;
    }

    return 1;
}
