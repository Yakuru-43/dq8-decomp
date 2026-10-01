// range: 0x1884C0 0x1884D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001884C0(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x5366) == 1;
}
