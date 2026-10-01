// range: 0x3280F0 0x328110
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003280F0(f32 arg0) {
    return M2C_BITWISE(s32, (0.5f + arg0));
}
