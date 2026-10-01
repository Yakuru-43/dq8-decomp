// range: 0x2D4620 0x2D4630
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D4620(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x34) != 0;
}
