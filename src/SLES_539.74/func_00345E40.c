// range: 0x345E40 0x345E80
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00345E80();                                /* extern */
extern s16 D_00453948 __attribute__((section(".data")));

s32 func_00345E40(void) {
    if ((func_00345E80() != 0) && (D_00453948 != 0)) {
        return 1;
    }
    return 0;
}
