// range: 0x35F270 0x35F290
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0035F270(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x1C) >= M2C_FIELD(arg0, s32 *, 8);
}
