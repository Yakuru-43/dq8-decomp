// range: 0x208B20 0x208B60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00306290(s32);                         /* extern */

void func_00208B20(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 0x10)) {
        func_00306290(arg0 + (arg1 * 0xC) + 0x67F4);
    }
}
