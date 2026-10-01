// range: 0x2D7030 0x2D7040
// auto: m2c, verified byte-exact
#include "common.h"

void func_002D7030(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
}
