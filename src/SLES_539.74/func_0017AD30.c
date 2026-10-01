// range: 0x17AD30 0x17AD40
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003DFC28;

s32 func_0017AD30(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_003DFC28;
    D_003DFC28 = arg0;
    return temp_v0;
}
