// range: 0x1A0F50 0x1A0F90
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E061C;
extern s32 D_00410E08 __attribute__((section(".data")));

s32 func_001A0F50(void) {
    if ((D_003E061C >= 5) && (D_00410E08 != 3)) {
        return 0;
    }
    return 1;
}
