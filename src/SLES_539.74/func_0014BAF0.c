// range: 0x14BAF0 0x14BB60
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014BAF0(char *arg0, char *arg1, char *arg2) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) (0.0078125f * (f32) M2C_FIELD(arg1, s8 *, 0) * M2C_FIELD(arg2, f32 *, 0));
    M2C_FIELD(arg0, f32 *, 4) = (f32) (0.0078125f * (f32) M2C_FIELD(arg1, s8 *, 1) * M2C_FIELD(arg2, f32 *, 4));
    M2C_FIELD(arg0, f32 *, 8) = (f32) (0.0078125f * (f32) M2C_FIELD(arg1, s8 *, 2) * M2C_FIELD(arg2, f32 *, 8));
}
