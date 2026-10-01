// range: 0x1666E0 0x166700
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001666E0(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg1, s32 *, 4);
    return arg0;
}
