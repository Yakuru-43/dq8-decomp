// range: 0x157F90 0x157FB0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00157F90(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (arg1 + 0x800);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (arg2 + 0x800);
}
