// range: 0x167EC0 0x167F00
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00167F00(s32);                         /* extern */

void func_00167EC0(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_00167F00(var_s0);
        var_s0 += 1;
    } while (var_s0 < 2);
}
