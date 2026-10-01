// range: 0x2C5240 0x2C5250
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 *D_003E1010;

s32 func_002C5240(void) {
    return *D_003E1010 > 0;
}
