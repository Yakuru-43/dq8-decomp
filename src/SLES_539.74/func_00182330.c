// range: 0x182330 0x182360
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0438;
extern s16 D_003E043C;

s32 func_00182330(void) {
    return D_003E0438 + (D_003E043C * 0x2490);
}
