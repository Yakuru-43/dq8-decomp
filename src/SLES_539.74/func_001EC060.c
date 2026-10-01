// range: 0x1EC060 0x1EC070
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001EC060(void *arg0, s32 *arg1) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0x8C);
    return M2C_FIELD(arg0, s32 *, 0x88);
}
