// range: 0x1D1DD0 0x1D1DF0
// auto: m2c, verified byte-exact
#include "common.h"

void func_001D1DD0(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = M2C_FIELD(arg0, f32 *, 0x6C);
    *arg2 = M2C_FIELD(arg0, f32 *, 0x70);
}
