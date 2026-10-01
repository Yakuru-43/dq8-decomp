// range: 0x340740 0x340750
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340740(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13) == 0x37;
}
