// range: 0x1D1F40 0x1D1FD0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(char *, M2C_UNK, M2C_UNK);    /* extern */

char *func_001D1F40(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, s32 *, 8) = -1;
    func_00131188(arg0 + 0xC, 0, 0x20);
    M2C_FIELD(arg0, s32 *, 0x2C) = 1;
    M2C_FIELD(arg0, s128 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x48) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x44) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x40) = 0x43000000;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    return arg0;
}
