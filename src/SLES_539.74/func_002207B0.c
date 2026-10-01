// range: 0x2207B0 0x220800
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00168150();                                /* extern */
s32 func_0016E2E0(s32, M2C_UNK);                    /* extern */

s32 func_002207B0(void) {
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_00168150();
    temp_s0 = func_0016E2E0(temp_v0, 0x10);
    return temp_s0 | (func_0016E2E0(temp_v0, 0x11) * 2);
}
