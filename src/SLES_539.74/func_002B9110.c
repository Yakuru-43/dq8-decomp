// range: 0x2B9110 0x2B9120
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0F94;

s32 func_002B9110(void) {
    return (u32) (D_003E0F94 - 1) < 2U;
}
