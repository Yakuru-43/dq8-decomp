// range: 0x1749E0 0x174A10
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_001749E0(s32 arg0) {
    s32 var_a2;
    char *temp_v1;

    var_a2 = 0;
    do {
        temp_v1= (char *) ( arg0 + (var_a2 * 8));
        var_a2 += 1;
        M2C_FIELD(temp_v1, s16 *, 0x160) = -1;
    } while (var_a2 < 0x10);
}
