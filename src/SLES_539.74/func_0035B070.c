// range: 0x35B070 0x35B0B0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0035B070(s32 arg0) {
    s32 var_a3;
    char *temp_a1;

    var_a3 = 0;
    do {
        temp_a1= (char *) ( arg0 + (var_a3 * 0x590));
        var_a3 += 1;
        M2C_FIELD(temp_a1, s8 *, 0x555) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x556) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x557) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x558) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x559) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x55A) = 0;
    } while (var_a3 < 0x20);
}
