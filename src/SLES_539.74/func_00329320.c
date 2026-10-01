// range: 0x329320 0x329330
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E121C;

s32 func_00329320(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_003E121C;
    D_003E121C = arg0;
    return temp_v0;
}
