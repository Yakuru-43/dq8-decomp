// range: 0x13EF90 0x13EFF0
#include "common.h"

void func_0013EF90(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *temp_t2;

    temp_t2 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_t2, s64 *, 0) =
        (s64) arg3 << 32 |
        ((s64) ((arg1 << 4) + M2C_FIELD(arg0, s32 *, 0x120)) |
         ((s64) ((arg2 << 4) + M2C_FIELD(arg0, s32 *, 0x124)) << 16));
    M2C_FIELD(temp_t2, s64 *, 8) = 5;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
