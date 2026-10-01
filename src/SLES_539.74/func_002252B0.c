// range: 0x2252B0 0x2252C0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002252B0(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x50) = arg1;
    M2C_FIELD(arg0, s16 *, 0x52) = 0;
}
