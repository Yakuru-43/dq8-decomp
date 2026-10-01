// range: 0x168900 0x168910
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_003E0364;

s32 func_00168900(s8 arg0) {
    D_003E0364 = arg0;
    return 0;
}
