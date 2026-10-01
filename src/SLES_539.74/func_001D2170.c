// range: 0x1D2170 0x1D21C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001D2480(s32);                         /* extern */

void func_001D2170(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_001D2480(arg0 + (var_s0 * 0x88));
        var_s0 += 1;
    } while (var_s0 < 8);
}
