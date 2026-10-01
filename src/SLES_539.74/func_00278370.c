// range: 0x278370 0x2783D0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00278780();                            /* extern */
extern M2C_UNK D_003DE858 __attribute__((section(".data")));

void *func_00278370(void *arg0) {
    func_00278780();
    M2C_FIELD(arg0, M2C_UNK **, 0x40) = &D_003DE858;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s8 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 1;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x60) = 0x3F800000;
    M2C_FIELD(arg0, s8 *, 0x68) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    return arg0;
}
