// range: 0x26CD50 0x26CDB0
// auto: m2c, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DE620 __attribute__((section(".data")));
extern M2C_UNK D_003DE770 __attribute__((section(".data")));
extern M2C_UNK D_003DE7A0 __attribute__((section(".data")));
extern M2C_UNK D_003DE7D0 __attribute__((section(".data")));

void *func_0026CD50(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE7D0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE7A0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE770;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE620;
    return arg0;
}
