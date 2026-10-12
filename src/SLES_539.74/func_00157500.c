// range: 0x157500 0x157540
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00157500(s32 arg0) {
    s32 temp_v1;
    s32 var_a3;
    char *temp_a2;

    var_a3 = 0;
    do {
        temp_v1 = var_a3 * 0x30;
        var_a3 += 1;
        temp_a2= (char *) ( arg0 + temp_v1);
        M2C_FIELD(temp_a2, s32 *, 0x100) = 0xBF800000;
        M2C_FIELD(temp_a2, s128 *, 0xF0) = 0;
        M2C_FIELD(temp_a2, s128 *, 0xE0) = 0;
    } while (var_a3 < 4);
}
