// range: 0x18F3F0 0x18F430
// auto: m2c, verified byte-exact
#include "common.h"

extern u16 D_003E053C;
extern s32 D_003E0540;

s32 func_0018F3F0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < (s32) D_003E053C)) {
        return D_003E0540 + (arg0 * 0x1C);
    }
    return 0;
}
