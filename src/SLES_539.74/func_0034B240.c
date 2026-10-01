// range: 0x34B240 0x34B2A0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0034B220();                                /* extern */
extern s32 D_003E0B34;

s32 func_0034B240(s32 arg0, s32 arg1) {
    if (arg1 < 0) {
        goto block_1;
    }
    if (arg1 < func_0034B220()) {
        return D_003E0B34 + (arg1 * 0x28) + 0x24;
    }
block_1:
    return 0;
}
