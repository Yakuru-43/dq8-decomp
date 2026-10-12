// range: 0x2889F0 0x288A70
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00166AC0(s32, s128 *, s128 *, s128 *); /* extern */
M2C_UNK func_001E7210(char *, s32, s32);            /* extern */

void func_002889F0(char *arg0, s32 arg1, s32 arg2) {
    s128 sp60;
    s128 sp50;
    s128 sp40;


    if (!(arg2 != 0)) {
        return;
    }

    sp60 = M2C_FIELD(arg0, s128 *, 0x180);
    sp50 = M2C_FIELD(arg0, s128 *, 0x190);
    sp40 = M2C_FIELD(arg0, s128 *, 0x1A0);
    func_00166AC0(arg2, &sp60, &sp50, &sp40);
    func_001E7210(arg0 + 0x1F0, arg1, arg2);
}
