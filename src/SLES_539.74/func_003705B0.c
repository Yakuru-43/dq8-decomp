// range: 0x3705B0 0x3705C0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003705B0(void *arg0, s32 arg1) {
    return (arg1 & M2C_FIELD(arg0, u8 *, 0x1E)) != 0;
}
