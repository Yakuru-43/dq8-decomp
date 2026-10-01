// range: 0x3766A0 0x3766D0
// auto: m2c, verified byte-exact
#include "common.h"

void func_003766A0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    if (arg2 != 0) {
        M2C_FIELD(arg0, s8 *, 0x15B) = 1;
    }
}
