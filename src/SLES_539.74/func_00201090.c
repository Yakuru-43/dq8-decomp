// range: 0x201090 0x2010F0
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_004159A0 __attribute__((section(".data")));

s32 func_00201090(void) {
    if ((D_004159A0 != 0x1C) && (D_004159A0 != 0) && (D_004159A0 != 4) && (D_004159A0 != 5) && (D_004159A0 != 0x15) && (D_004159A0 != 2)) {
        return 0;
    }
    return 1;
}
