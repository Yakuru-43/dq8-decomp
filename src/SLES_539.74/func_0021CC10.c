// range: 0x21CC10 0x21CC20
// auto: m2c, verified byte-exact
#include "common.h"

void func_0021CC10(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xF0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xF4) = (s32) M2C_FIELD(arg0, s32 *, 0xF0);
}
