// range: 0x35C5F0 0x35C640
// auto: m2c, verified byte-exact
#include "common.h"

void func_0035C5F0(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) M2C_FIELD(arg1, s32 *, 0);
        M2C_FIELD(arg0, s32 *, 0xE8) = (s32) M2C_FIELD(arg1, s32 *, 8);
        M2C_FIELD(arg0, s32 *, 0xEC) = (s32) M2C_FIELD(arg1, s32 *, 0xC);
        M2C_FIELD(arg0, s32 *, 0xF0) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
        M2C_FIELD(arg0, s32 *, 0xF4) = (s32) M2C_FIELD(arg1, s32 *, 0x14);
        M2C_FIELD(arg0, s32 *, 0x368) = (s32) M2C_FIELD(arg1, s32 *, 0x288);
        M2C_FIELD(arg0, s32 *, 0x36C) = (s32) M2C_FIELD(arg1, s32 *, 0x28C);
    }
}
