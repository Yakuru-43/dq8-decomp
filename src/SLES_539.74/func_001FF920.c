// range: 0x1FF920 0x1FF930
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001FF920(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x44B8);
}
