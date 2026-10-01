// range: 0x171A60 0x171A80
// auto: m2c, verified byte-exact
#include "common.h"

void func_00171A60(void *arg0) {
    M2C_FIELD(arg0, s16 *, 4) = 1;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}
