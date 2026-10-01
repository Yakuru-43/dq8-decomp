// range: 0x18CA00 0x18CA30
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0018CA00(char *arg0) {
    s32 var_a1;
    char *temp_v0;

    var_a1 = 0;
    do {
        temp_v0 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v0, s32 *, 0x6B20) = -1;
    } while (var_a1 < 2);
    M2C_FIELD(arg0, s32 *, 0x6B1C) = 0;
    return 0;
}
