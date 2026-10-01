// range: 0x340900 0x340920
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340900(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC) == (M2C_FIELD(arg0, s32 *, 8) - 1);
}
