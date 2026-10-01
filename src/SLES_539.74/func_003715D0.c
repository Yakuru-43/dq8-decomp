// range: 0x3715D0 0x3715E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003715D0(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x16) + M2C_FIELD(arg0, s16 *, 0x12);
}
