// range: 0x386940 0x386970
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00386940(s32 arg0) {
    s32 var_a2;
    char *temp_a1;

    var_a2 = 0;
    do {
        temp_a1= (char *) ( arg0 + (var_a2 * 0x10));
        var_a2 += 1;
        M2C_FIELD(temp_a1, s32 *, 0) = 0;
        M2C_FIELD(temp_a1, s32 *, 4) = 0;
        M2C_FIELD(temp_a1, s32 *, 8) = 0;
        M2C_FIELD(temp_a1, s32 *, 0xC) = 0;
    } while (var_a2 < 4);
}
