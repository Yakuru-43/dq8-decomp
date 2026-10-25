// range: 0x13ECD0 0x13ED40
#include "common.h"

void func_0013ECD0(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *temp_a3;

    temp_a3 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_a3, s64 *, 0) =
        (s64) arg1 | ((s64) arg2 << 8) | ((s64) arg3 << 16) | ((s64) arg4 << 24) |
        (u64) M2C_FIELD(arg0, u32 *, 0x110) << 32;
    M2C_FIELD(temp_a3, s64 *, 8) = 1;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
