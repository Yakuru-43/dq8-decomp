// range: 0x15DC70 0x15DC80
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0298;

void func_0015DC70(s32 arg0) {
    M2C_FIELD(D_003E0298, s32 *, 0x3CB8) = arg0;
}
