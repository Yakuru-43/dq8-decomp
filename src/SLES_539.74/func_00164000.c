// range: 0x164000 0x164010
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E0340;

s32 func_00164000(s32 arg0) {
    D_003E0340 = arg0;
    return 1;
}
