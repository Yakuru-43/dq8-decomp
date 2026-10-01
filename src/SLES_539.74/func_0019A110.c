// range: 0x19A110 0x19A150
// auto: m2c, verified byte-exact
#include "common.h"

void func_0019A110(void *arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) ((f32) 0x2710 + M2C_FIELD(arg0, f32 *, 0));
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) - (f32) 0x1770);
}
