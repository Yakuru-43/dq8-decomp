// range: 0x27B5E0 0x27B5F0
// auto: m2c, verified byte-exact
#include "common.h"

void func_0027B5E0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1C8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C8) | arg1);
}
