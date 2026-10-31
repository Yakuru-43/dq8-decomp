// range: 0x13EC20 0x13EC60
#include "common.h"

void func_0013EC20(char *arg0, s32 arg1, s32 arg2) {
    char *temp_a2;

    temp_a2 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(temp_a2, s64 *, 0) = (s64) arg1 | ((s64) arg2 << 16);
    M2C_FIELD(temp_a2, s64 *, 8) = 3;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
