// range: 0x290D70 0x290DF0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00290D70(char *arg0) {
    s32 var_a3;
    s32 var_a3_2;
    char *temp_a2;
    char *temp_a2_2;

    M2C_FIELD(arg0, s32 *, 0xD8) = 0;
    M2C_FIELD(arg0, s32 *, 0xDC) = 0;
    var_a3 = 0;
    M2C_FIELD(arg0, s8 *, 0x4EC) = 1;
    M2C_FIELD(arg0, s32 *, 0xE0) = 0;
    do {
        temp_a2 = arg0 + (var_a3 * 4);
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 0xE4) = -1;
        M2C_FIELD(temp_a2, s32 *, 0xFC) = 0;
        M2C_FIELD(temp_a2, s32 *, 0x114) = 0;
        M2C_FIELD(temp_a2, s32 *, 0x12C) = 0;
    } while (var_a3 < 6);
    M2C_FIELD(arg0, s32 *, 0x15C) = 0;
    var_a3_2 = 0;
    do {
        temp_a2_2 = arg0 + (var_a3_2 * 4);
        var_a3_2 += 1;
        M2C_FIELD(temp_a2_2, s32 *, 0x160) = -1;
        M2C_FIELD(temp_a2_2, s32 *, 0x1E0) = 0;
        M2C_FIELD(temp_a2_2, s32 *, 0x260) = 0;
        M2C_FIELD(temp_a2_2, s32 *, 0x2E0) = 0;
        M2C_FIELD(temp_a2_2, s32 *, 0x360) = 0;
    } while (var_a3_2 < 0x20);
}
