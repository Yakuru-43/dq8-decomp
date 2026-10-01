// range: 0x2344F0 0x234530
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002344F0(char *arg0) {
    s32 var_a1;
    char *temp_v1;

    var_a1 = 0;
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    do {
        temp_v1 = arg0 + (var_a1 * 4);
        var_a1 += 1;
        M2C_FIELD(temp_v1, s32 *, 8) = 0;
    } while (var_a1 < 4);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
}
