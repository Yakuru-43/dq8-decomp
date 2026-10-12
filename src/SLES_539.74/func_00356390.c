// range: 0x356390 0x3563E0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00356390(char *arg0) {
    s32 temp_v1;
    s32 var_a3;
    char *temp_a2;

    var_a3 = 0;
    do {
        temp_v1 = var_a3 * 0x30;
        var_a3 += 1;
        temp_a2 = arg0 + temp_v1;
        M2C_FIELD(temp_a2, s32 *, 0) = 0;
        M2C_FIELD(temp_a2, s32 *, 0x20) = -1;
        M2C_FIELD(temp_a2, s32 *, 0x24) = -1;
        M2C_FIELD(temp_a2, s32 *, 0x28) = -1;
        M2C_FIELD(temp_a2, s128 *, 0x10) = 0;
    } while (var_a3 < 0x20);
    M2C_FIELD(arg0, s32 *, 0x600) = -1;
    M2C_FIELD(arg0, s32 *, 0x604) = 0x10B;
}
