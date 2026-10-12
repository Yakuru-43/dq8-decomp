// range: 0x1A9260 0x1A92B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0();              /* extern */
extern M2C_UNK D_003C3E50 __attribute__((section(".data")));

s32 func_001A9260(s32 arg0, char *arg1) {
    M2C_FIELD(arg1, s32 *, 0xDC) = 0;
    M2C_FIELD(arg1, s32 *, 0xE0) = 0;
    M2C_FIELD(arg1, s32 *, 0xE4) = 0;
    M2C_FIELD(arg1, s128 *, 0xF0) = 0;
    M2C_FIELD(arg1, s32 *, 0x100) = 0;
    M2C_FIELD(arg1, s32 *, 0x104) = 0;
    M2C_FIELD(arg1, s32 *, 0x108) = 0;
    func_001340C0(arg1 + 0x10C, &D_003C3E50);
    return 0;
}
