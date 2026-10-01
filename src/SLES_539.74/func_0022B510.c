// range: 0x22B510 0x22B530
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0AE0;

s32 func_0022B510(s32 arg0) {
    D_003E0AE0 |= arg0;
    return 1;
}
