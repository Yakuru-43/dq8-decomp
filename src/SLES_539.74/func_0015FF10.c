// range: 0x15FF10 0x15FF20
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E032C;

s32 func_0015FF10(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_003E032C;
    D_003E032C = arg0;
    return temp_v0;
}
