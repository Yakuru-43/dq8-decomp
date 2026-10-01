// range: 0x33A620 0x33A650
// auto: m2c, verified byte-exact
#include "common.h"

void func_0033A620(void *arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0x20C);
    M2C_FIELD(arg1, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0x210);
    M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x214);
    M2C_FIELD(arg1, s32 *, 0xC) = 0x3F800000;
}
