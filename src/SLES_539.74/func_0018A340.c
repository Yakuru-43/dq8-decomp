// range: 0x18A340 0x18A360
// auto: m2c, verified byte-exact
#include "common.h"

void func_0018A340(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, u8 *, 0x68CC) = (u8) arg1;
    M2C_FIELD(arg0, u8 *, 0x68CD) = (u8) arg2;
    M2C_FIELD(arg0, u8 *, 0x68CE) = (u8) arg3;
    M2C_FIELD(arg0, u8 *, 0x68CF) = (u8) arg4;
}
