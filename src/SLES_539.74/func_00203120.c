// range: 0x203120 0x203140
// auto: m2c, verified byte-exact
#include "common.h"

void func_00203120(void *arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) M2C_FIELD(arg0, f32 *, 0xA68);
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0xA6C);
    M2C_FIELD(arg1, s32 *, 0xC) = 0x3F800000;
}
