// range: 0x2361D0 0x2361F0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002361D0(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x204) = arg1;
    if (M2C_FIELD(arg0, s32 *, 0x204) == -1) {
        M2C_FIELD(arg0, s32 *, 0x208) = 0;
    }
}
