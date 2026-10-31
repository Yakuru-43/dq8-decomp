// range: 0x13F070 0x13F0B0
#include "common.h"

void func_0013F070(char *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, char **, 0xF4), u128 *, 0) = 0;
    M2C_FIELD(M2C_FIELD(arg0, char **, 0xF4), s32 *, 0) = 0x50000000;
    M2C_FIELD(M2C_FIELD(arg0, char **, 0xF4), s32 *, 4) = arg1 & 0x0FFFFFFF;
    M2C_FIELD(arg0, char **, 0xF4) = (char *) (M2C_FIELD(arg0, char **, 0xF4) + 0x10);
}
