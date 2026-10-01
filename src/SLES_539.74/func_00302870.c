// range: 0x302870 0x302890
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00302870(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) + (M2C_FIELD(arg0, s32 *, 0x1C) << 6);
}
