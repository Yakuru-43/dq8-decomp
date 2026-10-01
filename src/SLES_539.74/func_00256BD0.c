// range: 0x256BD0 0x256C10
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0BD0;
extern u16 D_003E0BD4;

s32 func_00256BD0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < (s32) D_003E0BD4)) {
        return D_003E0BD0 + (arg0 << 5);
    }
    return 0;
}
