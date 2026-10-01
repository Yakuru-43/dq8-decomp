// range: 0x1452B0 0x1452D0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_001452B0(char *arg0, char *arg1) {
    char *temp_a0;

    temp_a0 = M2C_FIELD(arg0, char **, 0x270);
    M2C_FIELD(arg1, s32 *, 0) = 0;
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(temp_a0, s32 *, 8);
    M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(temp_a0, s32 *, 4);
}
