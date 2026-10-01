// range: 0x1EE3A0 0x1EE3B0
// auto: m2c, verified byte-exact
#include "common.h"

void func_001EE3A0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (arg1 != 0);
}
