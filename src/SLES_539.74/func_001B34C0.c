// range: 0x1B34C0 0x1B34D0
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0664;

s32 func_001B34C0(void) {
    M2C_FIELD(D_003E0664, s8 *, 0x67E1) = 0;
    return 1;
}
