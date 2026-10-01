// range: 0x1499D0 0x1499F0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001499D0(char *arg0, f32 fparg0) {
    M2C_FIELD(arg0, s16 *, 0x2E) = M2C_BITWISE(s16, (16384.0f * fparg0));
}
