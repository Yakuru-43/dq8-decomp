// range: 0x35FDE0 0x35FE00
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_00456FC0 __attribute__((section(".data")));
extern s32 D_00456FC4 __attribute__((section(".data")));

s32 func_0035FDE0(void) {
    return (D_00456FC0 + 1) == D_00456FC4;
}
