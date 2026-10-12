// range: 0x26D500 0x26D560
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DE140 __attribute__((section(".data")));
extern M2C_UNK D_003DE170 __attribute__((section(".data")));
extern M2C_UNK D_003DE7D0 __attribute__((section(".data")));

char *func_0026D500(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE7D0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE170;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s128 *, 0x20) = 0;
    M2C_FIELD(arg0, s128 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s128 *, 0x50) = 0;
    M2C_FIELD(arg0, s128 *, 0x60) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE140;
    return arg0;
}
