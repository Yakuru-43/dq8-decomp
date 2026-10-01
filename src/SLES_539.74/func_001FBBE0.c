// range: 0x1FBBE0 0x1FBC10
// auto: m2c, verified byte-exact
#include "common.h"

s8 func_001667C0();                                 /* extern */
extern s8 D_00415823 __attribute__((section(".data")));

s32 func_001FBBE0(void) {
    D_00415823 = func_001667C0();
    return 1;
}
