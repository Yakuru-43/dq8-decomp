// range: 0x2E5150 0x2E5170
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002E5150(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x119C) != M2C_FIELD(arg0, s32 *, 0x11A0);
}
