// range: 0x2D43C0 0x2D43D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002D43C0(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 4) == arg1;
}
