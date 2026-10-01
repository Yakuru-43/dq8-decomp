// range: 0x1C28D0 0x1C28E0
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0664;

s32 func_001C28D0(void) {
    M2C_FIELD(D_003E0664, s8 *, 0x55F4) = 0;
    return 1;
}
