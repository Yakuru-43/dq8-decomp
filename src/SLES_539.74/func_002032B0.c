// range: 0x2032B0 0x2032E0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_002032B0(s32 arg0) {
    s32 var_a1;
    char *temp_v1;

    var_a1 = 0;
    do {
        temp_v1= (char *) ( arg0 + (var_a1 * 4));
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x20) = 0;
    } while (var_a1 < 8);
}
