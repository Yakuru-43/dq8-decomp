// range: 0x375AC0 0x375B10
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00375AC0(char *arg0) {
    s32 var_a3;
    char *temp_a2;

    M2C_FIELD(arg0, s16 *, 0) = 0;
    var_a3 = 0;
    do {
        temp_a2 = arg0 + (var_a3 * 4);
        var_a3 += 1;
        M2C_FIELD(temp_a2, s32 *, 4) = 0x3F800000;
        M2C_FIELD(temp_a2, s32 *, 0x14) = 0xBF800000;
        M2C_FIELD(temp_a2, s32 *, 0x24) = 0;
    } while (var_a3 < 4);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x3C) = 0;
    return arg0;
}
