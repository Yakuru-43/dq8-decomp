// range: 0x3866C0 0x3866D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003866C0(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x9C) > 0;
}
