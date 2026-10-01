// range: 0x2C15D0 0x2C1640
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002C15D0(char *arg0) {
    s32 var_a1;
    s32 var_a1_2;
    char *temp_v1;
    char *temp_v1_2;

    M2C_FIELD(arg0, s8 *, 0x2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x2E) = 0;
    var_a1 = 0;
    M2C_FIELD(arg0, s8 *, 0x2F) = -1;
    M2C_FIELD(arg0, s8 *, 0xB1) = -1;
    M2C_FIELD(arg0, s8 *, 0x2D) = 0;
    M2C_FIELD(arg0, s8 *, 0xB2) = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x8C) = 0;
    } while (var_a1 < 5);
    var_a1_2 = 0;
    do {
        temp_v1_2 = arg0 + (var_a1_2 * 4);
        var_a1_2 += 1;
        M2C_FIELD(temp_v1_2, s32 *, 0xA0) = 0;
    } while (var_a1_2 < 4);
}
