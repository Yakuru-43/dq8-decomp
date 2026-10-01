// range: 0x18CB50 0x18CBB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

void func_0018CB50(char *arg0) {
    s32 var_s0;

    var_s0 = 0;
    M2C_FIELD(arg0, s8 *, 0x5341) = -1;
    do {
        func_00131188(arg0 + (var_s0 * 8) + 0x5344, 0, 8);
        var_s0 += 1;
    } while (var_s0 < 2);
}
