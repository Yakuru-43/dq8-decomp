// range: 0x18AEF0 0x18AF90
#include "common.h"

s32 func_0017A620();
s32 func_0018AF90(char *, s32, s32, char *);

s32 func_0018AEF0(char *arg0) {
    s32 temp_s0;
    s32 temp_v0;

    if (*(s16 *)(arg0 + 0x53E0) == 0) {
        return 1;
    }
    if (func_0017A620() != 0) {
        return 0;
    }
    if (*(s32 *)(arg0 + 0x55DC) == 0) {
        return 1;
    }
    temp_s0 = *(s16 *)(arg0 + 0x53E0) - 1;
    temp_v0 = func_0018AF90(arg0, *(s32 *)(arg0 + 0x55E0), temp_s0, arg0 + 0x53E4);
    if (temp_v0 < 0) {
        return 0;
    }
    if (temp_v0 == temp_s0) {
        *(s16 *)(arg0 + 0x53E0) = 0;
        return 1;
    }
    *(s16 *)(arg0 + 0x53E0) = (s16)(temp_v0 + 1);
    return 0;
}
