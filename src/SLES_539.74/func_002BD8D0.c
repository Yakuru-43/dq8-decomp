// range: 0x2BD8D0 0x2BD910
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E1000;

s32 func_002BD8D0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        return D_003E1000 + (arg0 * 0x70);
    }
    return 0;
}
