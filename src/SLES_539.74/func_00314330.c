// range: 0x314330 0x314360
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00314330(s32 arg0) {
    s32 var_a3;
    char *temp_a2;

    var_a3 = 0;
    do {
        temp_a2= (char *) ( arg0 + (var_a3 * 4));
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 0) = -1;
        M2C_FIELD(temp_a2, s32 *, 0x80) = 0;
    } while (var_a3 < 0x20);
}
