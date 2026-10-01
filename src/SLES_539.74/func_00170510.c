// range: 0x170510 0x170520
// auto: m2c, verified byte-exact
#include "common.h"

void func_00170510(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x214) = arg1;
}
