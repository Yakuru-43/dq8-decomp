// range: 0x361AE0 0x361B20
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00361AE0(char *arg0) {
    s32 var_a1;
    char *temp_v0;

    var_a1 = 0;
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    do {
        temp_v0 = arg0 + (var_a1 * 2);
        var_a1 += 1;
        M2C_FIELD(temp_v0, s16 *, 8) = -1;
    } while (var_a1 < 8);
    return arg0;
}
