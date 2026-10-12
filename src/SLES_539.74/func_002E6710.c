// range: 0x2E6710 0x2E6740
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_002E6710(s32 arg0, s32 arg1) {
    s32 var_a2;
    char *temp_v1;

    var_a2 = 0;
    do {
        temp_v1= (char *) ( arg0 + (var_a2 * 4));
        var_a2 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x17E8) = arg1;
    } while (var_a2 < 0x14);
}
