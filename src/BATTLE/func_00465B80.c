// range: 0x465B80 0x465C00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00466940(s32, M2C_UNK, s32);           /* extern */

void func_00465B80(s32 arg0, M2C_UNK arg1) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_00466940(arg0 + (var_s0 * 0x260), arg1, M2C_FIELD((arg0 + (var_s0 * 4)), s32 *, 0x3900));
        var_s0 += 1;
    } while (var_s0 < 0x18);
}
