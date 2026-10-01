// range: 0x172B30 0x172B50
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0404;

s32 func_00172B30(void) {
    s32 temp_hi;

    temp_hi = (s32) (D_003E0404 + 1) % 25;
    D_003E0404 = temp_hi;
    return temp_hi + 0x34;
}
