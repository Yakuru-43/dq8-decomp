// range: 0x22BD40 0x22BD60
// auto: m2c, verified byte-exact
#include "common.h"

void func_0022BD40(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) arg1;
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) arg2;
}
