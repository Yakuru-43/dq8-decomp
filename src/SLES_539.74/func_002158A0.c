// range: 0x2158A0 0x2158B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002158A0(void *arg0, s32 arg1) {
    return (arg1 & M2C_FIELD(arg0, s32 *, 0x2C)) != 0;
}
