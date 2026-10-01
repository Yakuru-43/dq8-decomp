// range: 0x1D1DF0 0x1D1E00
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001D1DF0(char *arg0, f32 fparg0, f32 fparg1) {
    M2C_FIELD(arg0, f32 *, 0x6C) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x70) = fparg1;
}
