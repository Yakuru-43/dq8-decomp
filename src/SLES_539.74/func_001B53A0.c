// range: 0x1B53A0 0x1B5420
#include "common.h"

char *func_00168150(void);
f32 func_0016E2B0(s32, s32);

s32 func_001B53A0(char *arg0, s32 arg1) {
    char *temp_v0;
    s32 temp_a1;
    f32 temp_f0;

    if (arg1 != 2) {
        return 0;
    }
    temp_v0 = func_00168150();
    if (*(s32 *)arg0 == 1) {
        temp_a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        temp_a1 = *(s32 *)(arg0 + 4);
    }
    temp_f0 = func_0016E2B0((s32)temp_v0, temp_a1);
    if (*(s32 *)(arg0 + 8) == 3) {
        *(f32 *)(*(char **)(arg0 + 0xC) + 4) = temp_f0;
    }
    return 1;
}
