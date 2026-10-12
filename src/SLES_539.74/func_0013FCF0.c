// range: 0x13FCF0 0x13FD20
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_0013FCF0(s32 arg0) {
    s32 var_a1;
    char *temp_v1;

    var_a1 = 0;
    do {
        temp_v1= (char *) ( arg0 + (var_a1 * 4));
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x3C38) = 0;
    } while (var_a1 < 0x20);
}
