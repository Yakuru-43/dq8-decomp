// range: 0x1A45E0 0x1A45F0
// auto: m2c, verified byte-exact
#include "common.h"

void func_001A45E0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x68) = arg1;
}
