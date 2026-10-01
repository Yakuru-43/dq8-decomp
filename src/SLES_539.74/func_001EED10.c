// range: 0x1EED10 0x1EED20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001EED10(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) != 0;
}
