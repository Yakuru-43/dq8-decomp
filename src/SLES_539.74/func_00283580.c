// range: 0x283580 0x2835A0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00283580(s32 arg0, s32 arg1, char **arg2) {
    char *temp_v1;

    temp_v1 = *arg2;
    M2C_FIELD(temp_v1, s32 *, 0x40) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x44) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x48) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x4C) = 0;
    M2C_FIELD(temp_v1, s32 *, 0x50) = 0;
    return 1;
}
