// range: 0x2D45D0 0x2D4620
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_00375910(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_002D45D0(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_00375910(temp_v0 + 0x30, arg3, arg2);
}
