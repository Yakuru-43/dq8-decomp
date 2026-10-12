// range: 0x2D4670 0x2D46D0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_00375900(s32, s32);                    /* extern */
s32 func_00375BD0(s32, M2C_UNK);                    /* extern */

void func_002D4670(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_00375900(temp_v0 + 0x30, func_00375BD0(arg0 + 0xC, arg2));
}
