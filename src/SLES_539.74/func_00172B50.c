// range: 0x172B50 0x172B70
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0400;

s32 func_00172B50(void) {
    s32 temp_hi;

    temp_hi = (s32) (D_003E0400 + 1) % 25;
    D_003E0400 = temp_hi;
    return temp_hi + 0x66;
}
