// range: 0x359010 0x3590A0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_00201760();                 /* extern */

void func_00359010(s32 arg0) {
    s16 temp_a0;
    s32 var_s0;
    char *temp_s2;

    var_s0 = 0;
    do {
        temp_s2= (char *) ( arg0 + (var_s0 * 0x590));
        temp_a0 = M2C_FIELD(temp_s2, s16 *, 0x10);
        if ((temp_a0 >= 2) && (temp_a0 < 6) && (func_00201760(temp_s2, 0) <= 0)) {
            M2C_FIELD(temp_s2, s8 *, 0x560) = 1;
            M2C_FIELD(temp_s2, s8 *, 0x561) = 0;
        }
        var_s0 += 1;
    } while (var_s0 < 0x20);
}
