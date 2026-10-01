// range: 0x2FF2B0 0x2FF300
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002FF2B0(char *arg0) {
    s32 var_a2;

    var_a2 = 0;
    M2C_FIELD(arg0, s32 *, 0) = -1;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 8) = -1;
    M2C_FIELD(arg0, s32 *, 0xC) = -1;
    do {
        if ((var_a2 >= 0) && (var_a2 < 4)) {
            M2C_FIELD((arg0 + (var_a2 * 4)), s32 *, 0x10) = -1;
        }
        var_a2 += 1;
    } while (var_a2 < 4);
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
}
