// range: 0x1AE200 0x1AE260
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001AE200(char *arg0) {
    s32 var_t1;
    char *temp_t0;

    M2C_FIELD(arg0, s32 *, 0x300) = 0;
    var_t1 = 0;
    do {
        temp_t0 = arg0 + (var_t1 << 6);
        var_t1 += 1;
        M2C_FIELD(temp_t0, s32 *, 0) = 0;
        M2C_FIELD(temp_t0, s32 *, 4) = 0;
        M2C_FIELD(temp_t0, s32 *, 8) = 0;
        M2C_FIELD(temp_t0, s128 *, 0x10) = 0;
        M2C_FIELD(temp_t0, s32 *, 0x20) = 0xBF800000;
        M2C_FIELD(temp_t0, s32 *, 0x28) = 0;
        M2C_FIELD(temp_t0, s32 *, 0x34) = 0;
        M2C_FIELD(temp_t0, s32 *, 0x2C) = 1;
        M2C_FIELD(temp_t0, s32 *, 0x30) = 3;
    } while (var_t1 < 0xC);
}
