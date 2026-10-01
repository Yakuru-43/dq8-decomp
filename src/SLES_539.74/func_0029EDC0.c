// range: 0x29EDC0 0x29EE50
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0029EDC0(char *arg0, s32 arg1, char *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg2, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg2, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg2, s32 *, 0x48);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg2, s32 *, 0x50);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg2, s32 *, 0x58);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg2, s32 *, 0x60);
    M2C_FIELD(arg0, char **, 4) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x34));
    M2C_FIELD(arg0, char **, 8) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x3C));
    M2C_FIELD(arg0, char **, 0xC) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x44));
    M2C_FIELD(arg0, char **, 0x10) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x4C));
    M2C_FIELD(arg0, char **, 0x14) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x54));
    M2C_FIELD(arg0, char **, 0x18) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x5C));
    M2C_FIELD(arg0, char **, 0x1C) = (char *) (arg2 + M2C_FIELD(arg2, s32 *, 0x64));
}
