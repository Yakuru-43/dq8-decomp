// range: 0x28F4C0 0x28F4F0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0028F4C0(char *arg0) {
    s32 var_a2;
    char *temp_a1;

    var_a2 = 0;
    do {
        temp_a1 = arg0 + (var_a2 * 4);
        var_a2 += 1;
        M2C_FIELD(temp_a1, s32 *, 0x3E4) = -1;
        M2C_FIELD(temp_a1, s32 *, 0x464) = 0;
    } while (var_a2 < 0x20);
    M2C_FIELD(arg0, s32 *, 0x3E0) = 0;
    return 0;
}
