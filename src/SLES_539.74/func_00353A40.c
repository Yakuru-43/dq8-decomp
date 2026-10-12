// range: 0x353A40 0x353A80
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00353A40(s32 arg0) {
    s32 var_a3;
    char *temp_a2;

    var_a3 = 0;
    do {
        temp_a2= (char *) ( arg0 + (var_a3 * 4));
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 0x648)= (s32) M2C_FIELD(temp_a2, s32 *, 0x618);
        M2C_FIELD(temp_a2, s32 *, 0x658)= (s32) M2C_FIELD(temp_a2, s32 *, 0x628);
        M2C_FIELD(temp_a2, s32 *, 0x638)= (s32) M2C_FIELD(temp_a2, s32 *, 0x608);
    } while (var_a3 < 4);
}
