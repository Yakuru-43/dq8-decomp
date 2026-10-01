// range: 0x276C00 0x276C40
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DE820 __attribute__((section(".data")));
extern M2C_UNK D_003DE840 __attribute__((section(".data")));

void *func_00276C00(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE840;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE820;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    return arg0;
}
