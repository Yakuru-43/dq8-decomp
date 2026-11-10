// range: 0x13F0B0 0x13F0D0
#include "common.h"

void func_0013F0B0(char *arg0, s32 arg1) {
    char *temp_v0;
    s32 temp_v1;

    temp_v1 = arg1 << 4;
    temp_v0 = M2C_FIELD(arg0, char **, 0xF4);
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (temp_v0 + temp_v1);
}
