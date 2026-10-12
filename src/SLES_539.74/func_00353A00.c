// range: 0x353A00 0x353A40
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

void func_00353A00(s32 arg0) {
    s32 var_a3;
    char *temp_a2;

    var_a3 = 0;
    do {
        temp_a2= (char *) ( arg0 + (var_a3 * 4));
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 0x618)= (s32) M2C_FIELD(temp_a2, s32 *, 0x648);
        M2C_FIELD(temp_a2, s32 *, 0x628)= (s32) M2C_FIELD(temp_a2, s32 *, 0x658);
        M2C_FIELD(temp_a2, s32 *, 0x608)= (s32) M2C_FIELD(temp_a2, s32 *, 0x638);
    } while (var_a3 < 4);
}
