// range: 0x1B6500 0x1B6590
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00145440(s32);                             /* extern */
s32 func_00145450(s32);                             /* extern */
s32 func_0015F490();                                /* extern */

s32 func_001B6500(void *arg0, s32 arg1) {
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;

    if (arg1 != 2) {
        return 0;
    }
    temp_v0 = func_0015F490();
    temp_s1 = func_00145450(temp_v0);
    temp_v0_2 = func_00145440(temp_v0);
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_s1;
    }
    if (M2C_FIELD(arg0, s32 *, 8) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 4) = temp_v0_2;
    }
    return 1;
}
