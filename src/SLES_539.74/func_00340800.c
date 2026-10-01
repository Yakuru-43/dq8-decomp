// range: 0x340800 0x340810
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340800(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13) == 0x42;
}
