// range: 0x2236A0 0x2236B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002236A0(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x2E) != 0;
}
