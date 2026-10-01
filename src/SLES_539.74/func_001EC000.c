// range: 0x1EC000 0x1EC050
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001EC000(void *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0x9C))) {
        return M2C_FIELD(arg0, s32 *, 0xA0) + (arg1 * 0x1D0);
    }
    return 0;
}
