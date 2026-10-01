// range: 0x324060 0x3240B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188();       /* extern */

void func_00324060(char *arg0) {
    func_00131188(arg0 + 0x28, 0, 0x24);
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = -1;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
}
