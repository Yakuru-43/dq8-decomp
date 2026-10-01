// range: 0x24EE10 0x24EE40
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003DFD78;
extern s32 D_003E0BB8;

s32 func_0024EE10(s32 arg0) {
    if (D_003E0BB8 == 0) {
        D_003DFD78 = arg0 - 5;
        D_003E0BB8 = 1;
        return 1;
    }
    return 0;
}
