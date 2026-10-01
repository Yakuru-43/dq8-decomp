// range: 0x1F9CA0 0x1F9D00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001EA770(M2C_UNK, char *, char *);     /* extern */

char *func_001F9CA0(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x14) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    func_001EA770(0, arg0 + 0x20, arg0 + 0x24);
    return arg0;
}
