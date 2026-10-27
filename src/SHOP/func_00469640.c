// range: 0x469640 0x469660
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00469640(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x28) + (M2C_FIELD(arg0, s32 *, 0x2C) * 0x10);
}
