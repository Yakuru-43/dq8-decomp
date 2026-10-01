// range: 0x22BD60 0x22BD80
// auto: m2c, verified byte-exact
#include "common.h"

void func_0022BD60(void *arg0, void *arg1) {
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) M2C_FIELD(arg1, s32 *, 4);
}
