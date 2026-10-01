// range: 0x28FCA0 0x28FCB0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0028FCA0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x4EC) == 6;
}
