// range: 0x2E4D90 0x2E4DA0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_002E4D90(char *arg0, f32 fparg0, f32 fparg1) {
    M2C_FIELD(arg0, f32 *, 0x16C) = fparg0;
    M2C_FIELD(arg0, f32 *, 0x170) = fparg1;
}
