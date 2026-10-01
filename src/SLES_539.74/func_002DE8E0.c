// range: 0x2DE8E0 0x2DE9D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167960();                                /* extern */
s32 func_00167990();                                /* extern */

void func_002DE8E0(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = func_00167990();
    temp_v0 = func_00167960();
    if (*arg0 < 0) {
        *arg0 = 0;
    }
    if (*arg0 >= temp_s0) {
        *arg0 = temp_s0 - 1;
    }
    if (*arg2 < 0) {
        *arg2 = 0;
    }
    if (*arg2 >= temp_s0) {
        *arg2 = temp_s0 - 1;
    }
    if (*arg1 < 0) {
        *arg1 = 0;
    }
    if (*arg1 >= temp_v0) {
        *arg1 = temp_v0 - 1;
    }
    if (*arg3 < 0) {
        *arg3 = 0;
    }
    if (*arg3 >= temp_v0) {
        *arg3 = temp_v0 - 1;
    }
}
