// range: 0x208BB0 0x208C10
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00306290(s32);                         /* extern */

void func_00208BB0(s32 arg0) {
    s32 var_s1;

    var_s1 = 0;
    do {
        func_00306290(arg0 + (var_s1 * 0xC) + 0x67F4);
        var_s1 += 1;
    } while (var_s1 < 0x10);
}
