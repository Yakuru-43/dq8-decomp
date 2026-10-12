// range: 0x2B11B0 0x2B11F0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_002B11B0(s32 arg0, s32 arg1) {
    s32 var_a2;
    char *temp_v1;

    var_a2 = 0;
    do {
        temp_v1= (char *) ( arg0 + (arg1 * 6) + (var_a2 * 2));
        var_a2 += 1;
        M2C_FIELD(temp_v1, s16 *, 0xA0) = 0;
    } while (var_a2 < 3);
}
