// range: 0x3405F0 0x340610
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003405F0(void *arg0, s32 arg1) {
    return (arg1 & (1 << M2C_FIELD(arg0, u8 *, 9))) != 0;
}
