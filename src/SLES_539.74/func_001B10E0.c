// range: 0x1B10E0 0x1B1180
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001B10E0(char *arg0) {
    s32 var_a2;
    char *temp_v1;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    var_a2 = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x20) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x24) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x28) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    do {
        temp_v1 = arg0 + (var_a2 << 6);
        var_a2 += 1;
        M2C_FIELD(temp_v1, s32 *, 0x90) = 0;
    } while (var_a2 < 0x20);
    M2C_FIELD(arg0, s32 *, 0x890) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0x40C00000;
}
