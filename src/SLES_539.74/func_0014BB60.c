// range: 0x14BB60 0x14BBD0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0014BB60(char *arg0, char *arg1, char *arg2) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) (0.000030517578f * (f32) M2C_FIELD(arg1, s16 *, 0) * M2C_FIELD(arg2, f32 *, 0));
    M2C_FIELD(arg0, f32 *, 4) = (f32) (0.000030517578f * (f32) M2C_FIELD(arg1, s16 *, 2) * M2C_FIELD(arg2, f32 *, 4));
    M2C_FIELD(arg0, f32 *, 8) = (f32) (0.000030517578f * (f32) M2C_FIELD(arg1, s16 *, 4) * M2C_FIELD(arg2, f32 *, 8));
}
