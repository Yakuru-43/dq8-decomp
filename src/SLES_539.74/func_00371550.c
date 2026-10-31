// range: 0x371550 0x3715A0
// auto: m2c draft, verified byte-exact
#include "common.h"

char * func_00130FD0(char *, const char *, u32);
char *func_00371550(char *arg0, char *arg1, s32 arg2) {
    func_00130FD0(arg0, arg1, 0x18U);
    M2C_FIELD(arg0, char **, 0x18) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = arg2;
    return arg0;
}
