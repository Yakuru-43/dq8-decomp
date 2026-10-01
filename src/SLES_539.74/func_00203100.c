// range: 0x203100 0x203120
// auto: m2c, verified byte-exact
#include "common.h"

void func_00203100(void *arg0, void *arg1) {
    M2C_FIELD(arg0, f32 *, 0xA68) = (f32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, f32 *, 0xA6C) = (f32) M2C_FIELD(arg1, f32 *, 8);
}
