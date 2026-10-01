// range: 0x1FBAF0 0x1FBB30
// auto: m2c draft, verified byte-exact
#include "common.h"

s8 func_001667C0();                                 /* extern */
extern s8 D_00415851 __attribute__((section(".data")));

s32 func_001FBAF0(s32 arg0, s32 arg1) {
    if (arg1 > 0) {
        D_00415851 = func_001667C0();
    }
    return 1;
}
