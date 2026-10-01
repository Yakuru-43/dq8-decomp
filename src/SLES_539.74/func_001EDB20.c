// range: 0x1EDB20 0x1EDB60
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001EF2E0();                                /* extern */
extern s32 D_003E0784;

s32 func_001EDB20(void) {
    if (func_001EF2E0() == 0) {
        D_003E0784 += 1;
        return 1;
    }
    return 1;
}
