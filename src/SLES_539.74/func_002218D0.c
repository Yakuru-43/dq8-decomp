// range: 0x2218D0 0x221900
// auto: m2c, verified byte-exact
#include "common.h"

void func_002218D0(s32 arg0) {
    s32 var_a1;

    var_a1 = 0;
    do {
        M2C_FIELD((arg0 + var_a1), s8 *, 0x1770) = 0;
        var_a1 += 1;
    } while (var_a1 < 0x10);
}
