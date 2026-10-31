// range: 0x1B54F0 0x1B5530
#include "common.h"

extern s32 D_003E0664;

s32 func_001B54F0(char *arg0) {
    s32 result;
    s32 *base;

    if (*(s32 *)arg0 == 1) {
        result = (s32) *(float *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    base = (s32 *)D_003E0664;
    if (base[0x539C / 4] != result) {
        base[0x53A4 / 4] = base[0x539C / 4];
    }
    base[0x539C / 4] = result;
    return 1;
}
