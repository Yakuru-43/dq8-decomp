// range: 0x375F60 0x375F80
// auto: m2c, verified byte-exact
#include "common.h"

void func_00375F60(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, f32 *, 4) = (f32) arg1;
    M2C_FIELD(arg0, f32 *, 8) = (f32) arg2;
}
