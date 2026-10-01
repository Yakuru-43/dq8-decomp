// range: 0x1F4920 0x1F4980
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_001E9D90();                            /* extern */

void func_001F4920(char *arg0) {
    func_001E9D90();
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 1;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    func_00131188(arg0 + 0x60, 0, 0x50);
}
