// range: 0x1F09B0 0x1F09D0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern f32 D_00414D20 __attribute__((section(".data")));
extern f32 D_00414D24 __attribute__((section(".data")));
extern f32 D_00414D28 __attribute__((section(".data")));

void func_001F09B0(f32 fparg0, f32 fparg1, f32 fparg2) {
    D_00414D20 = fparg0;
    D_00414D24 = fparg1;
    D_00414D28 = fparg2;
}
