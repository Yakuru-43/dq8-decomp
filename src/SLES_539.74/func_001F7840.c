// range: 0x1F7840 0x1F7850
// auto: m2c, verified byte-exact
#include "common.h"

void func_001F7840(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x15F0) = arg2;
    M2C_FIELD(arg0, s32 *, 0x15F4) = arg1;
}
