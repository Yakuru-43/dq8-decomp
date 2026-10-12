// range: 0x15DE20 0x15DE70
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

extern char *D_003E0298;

void func_0015DE20(s32 arg0, s128 *arg1, s128 *arg2) {
    s32 temp_a3;
    char *temp_a0;

    temp_a3 = M2C_FIELD(D_003E0298, s32 *, 0x36B0);
    if ((temp_a3 != 0) && (arg0 >= 0) && (arg0 < 4)) {
        temp_a0= (char *) ( temp_a3 + (arg0 * 0x10));
        M2C_FIELD(temp_a0, s128 *, 0x20)= (s128) *arg1;
        M2C_FIELD(temp_a0, s32 *, 0x2C) = 0;
        M2C_FIELD(temp_a0, s128 *, 0x60)= (s128) *arg2;
    }
}
