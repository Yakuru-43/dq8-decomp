// range: 0x372400 0x372430
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00372400(s32 arg0) {
    s32 var_a3;
    char *temp_a2;

    var_a3 = 0;
    do {
        temp_a2= (char *) ( arg0 + (var_a3 * 4));
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 0) = 0;
        M2C_FIELD(temp_a2, s32 *, 0x18) = 0x3F800000;
    } while (var_a3 < 6);
}
