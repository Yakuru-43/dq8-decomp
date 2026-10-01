// range: 0x26F0D0 0x26F0F0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0026F0D0(s32 arg0, s32 arg1, char **arg2) {
    char *temp_v1;

    temp_v1 = *arg2;
    M2C_FIELD(temp_v1, s32 *, 0x34) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x38) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x3C) = 0;
    return 1;
}
