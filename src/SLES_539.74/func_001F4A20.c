// range: 0x1F4A20 0x1F4A60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001E9D90();                            /* extern */

void func_001F4A20(void *arg0) {
    func_001E9D90();
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 1;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
}
