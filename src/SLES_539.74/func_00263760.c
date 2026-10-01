// range: 0x263760 0x2637A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00261230(s8 *, s32, M2C_UNK);              /* extern */
extern s8 D_0041E470 __attribute__((section(".data")));

s32 func_00263760(s32 arg0, M2C_UNK arg1) {
    if (D_0041E470 == 0) {
        return 0;
    }
    return func_00261230(&D_0041E470, arg0, arg1);
}
