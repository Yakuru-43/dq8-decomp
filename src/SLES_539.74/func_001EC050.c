// range: 0x1EC050 0x1EC060
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001EC050(void *arg0, s32 *arg1) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0x94);
    return M2C_FIELD(arg0, s32 *, 0x90);
}
