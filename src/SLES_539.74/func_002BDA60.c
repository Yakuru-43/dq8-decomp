// range: 0x2BDA60 0x2BDA70
// auto: m2c, verified byte-exact
#include "common.h"

void func_002BDA60(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x464) = (s32) (arg1 + 1);
}
