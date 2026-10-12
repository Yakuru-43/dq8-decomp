// range: 0x2B9360 0x2B9380
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002B9360(char *arg0, s32 arg1, s32 arg2, s128 *arg3, f32 fparg0) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10) = arg2;
    M2C_FIELD(arg0, s128 *, 0x20) = (s128) *arg3;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, f32 *, 0x34) = fparg0;
}
