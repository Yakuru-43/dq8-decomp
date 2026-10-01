// range: 0x375A80 0x375AC0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00375A80(char *arg0) {
    s32 var_t0;
    char *temp_a3;

    M2C_FIELD(arg0, s16 *, 0) = 0;
    var_t0 = 0;
    do {
        temp_a3 = arg0 + (var_t0 * 4);
        var_t0 += 1;
        M2C_FIELD(temp_a3, s32 *, 4) = 0x3F800000;
        M2C_FIELD(temp_a3, s32 *, 0x14) = 0xBF800000;
        M2C_FIELD(temp_a3, s32 *, 0x24) = 0;
    } while (var_t0 < 4);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x3C) = 0;
}
