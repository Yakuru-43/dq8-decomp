// range: 0x308030 0x308040
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00308030(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x5C10);
}
