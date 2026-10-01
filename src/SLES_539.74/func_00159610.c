// range: 0x159610 0x159620
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00159610(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1F4);
    M2C_FIELD(arg0, s32 *, 0x1F4) = arg1;
    return temp_v0;
}
