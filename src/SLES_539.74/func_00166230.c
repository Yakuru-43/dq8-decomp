// range: 0x166230 0x166270
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00166220(s32, M2C_UNK);                /* extern */
M2C_UNK func_00166270();                            /* extern */

void func_00166230(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_00166270();
    func_00166220(arg0, arg2);
}
