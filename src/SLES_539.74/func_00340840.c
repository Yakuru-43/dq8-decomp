// range: 0x340840 0x340850
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340840(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13) == 1;
}
