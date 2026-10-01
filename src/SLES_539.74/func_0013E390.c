// range: 0x13E390 0x13E3D0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00157990(s32, M2C_UNK);                /* extern */

void func_0013E390(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        func_00157990(arg0 + 0x10, 0);
        return;
    }
    func_00157990(arg0 + 0x10, 2);
}
