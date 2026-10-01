// range: 0x1AF770 0x1AF7C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001AF770(char *arg0, s32 arg1, f32 fparg0) {
    if (M2C_FIELD(arg0, s32 *, 0) >= 0) {
        M2C_FIELD(arg0, s32 *, 0) = -1;
        M2C_FIELD(arg0, s32 *, 4) = -1;
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
        M2C_FIELD(arg0, s32 *, 0x18) = 0;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0x3F800000;
    }
    M2C_FIELD(arg0, s32 *, 0) = 2;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, f32 *, 0x2C) = fparg0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0xBF800000;
    return 1;
}
