// range: 0x28A590 0x28A5A0
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0E10;

s32 func_0028A590(void) {
    M2C_FIELD(D_003E0E10, s32 *, 0x150) = 0;
    return 1;
}
