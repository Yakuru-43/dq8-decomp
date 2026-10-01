// range: 0x375F20 0x375F50
// auto: m2c, verified byte-exact
#include "common.h"

void func_00375F20(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (f32) M2C_FIELD(arg0, s16 *, 0x1C);
    *arg2 = (f32) M2C_FIELD(arg0, s16 *, 0x1E);
}
