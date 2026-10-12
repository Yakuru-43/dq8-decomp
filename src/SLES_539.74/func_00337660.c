// range: 0x337660 0x3376E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00337170(s32, s32);                    /* extern */
M2C_UNK func_003376E0(s32, s32);                    /* extern */

void func_00337660(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

    if (!((arg1 != 0) && (arg2 != 0))) {
        return;
    }

    func_00337170(arg1, arg0);
    if (arg3 != 0) {
        func_003376E0(arg0, arg1);
    }
}
