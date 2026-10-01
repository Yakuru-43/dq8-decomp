// range: 0x30D180 0x30D1A0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0030D180(void *arg0, void *arg1) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, s8 *, 4) = (s8) M2C_FIELD(arg1, s8 *, 4);
    return arg0;
}
