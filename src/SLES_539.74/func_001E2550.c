// range: 0x1E2550 0x1E2570
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001E2550(char *arg0, char *arg1) {
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(arg1, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x20) = (s128) M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(arg0, s32 *, 4) = 1;
}
