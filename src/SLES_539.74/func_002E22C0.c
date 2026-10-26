// range: 0x2E22C0 0x2E22E0
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E22C0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, u8 *, 0x88) = (u8) arg1;
    M2C_FIELD(arg0, u8 *, 0x89) = (u8) arg2;
    M2C_FIELD(arg0, u8 *, 0x8A) = (u8) arg3;
    M2C_FIELD(arg0, u8 *, 0x8B) = (u8) arg4;
}
