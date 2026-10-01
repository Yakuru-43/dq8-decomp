// range: 0x301170 0x301190
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00301170(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
    return 2;
}
