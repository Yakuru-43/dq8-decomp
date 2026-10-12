// range: 0x2098A0 0x2098D0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_002098A0(s32 arg0) {
    s32 var_a2;
    char *var_a1;

    var_a1= (char *) ( arg0 + 0x5D58);
    var_a2 = 0;
    do {
        M2C_FIELD(var_a1, s32 *, 0) = -1;
        var_a2 += 1;
        M2C_FIELD(var_a1, s32 *, 4) = 0;
        var_a1 += 0x88;
    } while (var_a2 < 4);
}
