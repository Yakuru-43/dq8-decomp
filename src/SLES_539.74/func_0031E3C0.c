// range: 0x31E3C0 0x31E410
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DEBC0 __attribute__((section(".data")));
extern M2C_UNK D_003DEC80 __attribute__((section(".data")));

char *func_0031E3C0(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x14) = &D_003DEC80;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x14) = &D_003DEBC0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (arg0 + 0x10);
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    return arg0;
}
