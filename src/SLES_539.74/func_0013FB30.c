// range: 0x13FB30 0x13FB90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0015C030();                         /* extern */

char *func_0013FB30(char *arg0) {
    func_0015C030(arg0 + 0x78);
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xE8) = 1;
    M2C_FIELD(arg0, s32 *, 0x110) = 0x3F800000;
    M2C_FIELD(arg0, s64 *, 0x70) = 0x100;
    M2C_FIELD(arg0, s32 *, 0xE0) = 1;
    M2C_FIELD(arg0, s32 *, 0xE4) = 0;
    M2C_FIELD(arg0, s32 *, 0x11C) = 0;
    M2C_FIELD(arg0, s32 *, 0x124) = 0;
    M2C_FIELD(arg0, s32 *, 0x120) = 0;
    return arg0;
}
