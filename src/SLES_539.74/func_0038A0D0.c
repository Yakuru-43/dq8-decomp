// range: 0x38A0D0 0x38A120
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0038A0D0(char *arg0, s32 arg1) {
    s32 var_a2;
    char *temp_a1;

    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    if (M2C_FIELD(arg0, s32 *, 0xC) == 0) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
        return;
    }
    var_a2 = 0;
    M2C_FIELD(arg0, s8 *, 0) = 1;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    do {
        temp_a1 = arg0 + (var_a2 << 6);
        var_a2 += 1;
        M2C_FIELD(temp_a1, s8 *, 0x20) = 0;
        M2C_FIELD(temp_a1, s8 *, 0x2F) = 0;
        M2C_FIELD(temp_a1, s32 *, 0x30) = 0;
        M2C_FIELD(temp_a1, s128 *, 0x50) = 0;
    } while (var_a2 < 4);
}
