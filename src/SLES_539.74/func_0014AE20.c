// range: 0x14AE20 0x14AE60
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014AE20(char *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x26) = (s16) (M2C_FIELD(arg0, s16 *, 0x26) | arg1);
    if (M2C_FIELD(arg0, s16 *, 0x26) & 0x10) {
        M2C_FIELD(arg0, s8 *, 0x2D) = 1;
    }
}
