// range: 0x1FF780 0x1FF790
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001FF780(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x34) - M2C_FIELD(arg0, s32 *, 0x2C);
}
