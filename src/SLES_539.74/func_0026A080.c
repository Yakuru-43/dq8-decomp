// range: 0x26A080 0x26A0A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0026A080(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xB4) + (M2C_FIELD(arg0, s32 *, 0xB0) * 0x10);
}
