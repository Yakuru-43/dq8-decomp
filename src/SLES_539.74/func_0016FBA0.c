// range: 0x16FBA0 0x16FBE0
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_0013BCA0();                                /* extern */

void func_0016FBA0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x218) = 1;
    M2C_FIELD(arg0, f32 *, 0x21C) = func_0013BCA0();
    M2C_FIELD(arg0, s8 *, 0x220) = 0;
    M2C_FIELD(arg0, s32 *, 0x224) = 0;
}
