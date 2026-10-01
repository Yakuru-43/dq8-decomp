// range: 0x35BC40 0x35BCA0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00359CF0(s32, s32);                      /* extern */

void func_0035BC40(s32 arg0) {
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_00359CF0(arg0, var_s0);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s16 *, 0xC8) = -1;
            M2C_FIELD(temp_v0, s16 *, 0xCA) = -1;
        }
        var_s0 += 1;
    } while (var_s0 < 4);
}
