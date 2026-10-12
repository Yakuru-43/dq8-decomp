// range: 0x2F6010 0x2F60A0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, s32);                    /* extern */
u32 func_001341D8(s32);                             /* extern */

void func_002F6010(s32 arg0, s32 arg1, s32 arg2) {

    if (!((arg1 >= 0) && (arg1 < 0xE) && (arg2 != 0))) {
        return;
    }

    if (func_001341D8(arg2) >= 0x3AU) {
        return;
    }
    func_001340C0(arg0 + (arg1 * 0x3A) + 0x11E9, arg2);
}
