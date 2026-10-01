// range: 0x340920 0x340930
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340920(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC) == 0;
}
