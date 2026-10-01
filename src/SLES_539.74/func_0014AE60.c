// range: 0x14AE60 0x14AE90
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014AE60(char *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x26) = arg1;
    if (M2C_FIELD(arg0, s16 *, 0x26) & 0x10) {
        M2C_FIELD(arg0, s8 *, 0x2D) = 1;
    }
}
