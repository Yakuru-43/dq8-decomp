// range: 0x301260 0x301280
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00301260(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
    return 1;
}
