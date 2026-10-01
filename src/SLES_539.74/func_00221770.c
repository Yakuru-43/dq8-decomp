// range: 0x221770 0x2217C0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00221830(M2C_UNK);                         /* extern */
M2C_UNK func_002F5FE0(s32, M2C_UNK, s32);           /* extern */

void func_00221770(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_002F5FE0(arg0, arg1, func_00221830(arg2));
}
