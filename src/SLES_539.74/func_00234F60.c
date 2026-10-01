// range: 0x234F60 0x234FD0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00234F60(char *arg0) {
    s32 var_a1;
    s32 var_a1_2;
    char *temp_v1;
    char *temp_v1_2;

    M2C_FIELD(arg0, s32 *, 0x818) = 0;
    M2C_FIELD(arg0, s32 *, 0x81C) = 1;
    M2C_FIELD(arg0, s32 *, 0x820) = 0x3F800000;
    var_a1 = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 4) = 0;
    } while (var_a1 < 0x200);
    M2C_FIELD(arg0, s32 *, 0x804) = 0;
    var_a1_2 = 0;
    do {
        temp_v1_2 = arg0 + (var_a1_2 * 4);
        var_a1_2 += 1;
        M2C_FIELD(temp_v1_2, s32 *, 0x808) = 0;
    } while (var_a1_2 < 4);
}
