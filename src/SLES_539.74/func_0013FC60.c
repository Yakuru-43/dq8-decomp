// range: 0x13FC60 0x13FC90
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0013FC60(s32 arg0) {
    s32 var_t0;
    char *temp_a3;

    var_t0 = 0;
    do {
        temp_a3= (char *) ( arg0 + (var_t0 * 0x10));
        var_t0 += 1;
        M2C_FIELD(temp_a3, s32 *, 0x3CC0) = 1;
        M2C_FIELD(temp_a3, s32 *, 0x3CCC) = -1;
    } while (var_t0 < 4);
}
