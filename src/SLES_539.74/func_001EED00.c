// range: 0x1EED00 0x1EED10
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001EED00(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x10);
}
