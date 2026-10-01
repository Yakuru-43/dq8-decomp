// range: 0x235FC0 0x236000
// auto: m2c draft, verified byte-exact
#include "common.h"

extern f32 D_004162AC __attribute__((section(".data")));
extern f32 D_004162B0 __attribute__((section(".data")));
extern f32 D_004162B4 __attribute__((section(".data")));
extern f32 D_004162B8 __attribute__((section(".data")));

void func_00235FC0(f32 fparg0, f32 fparg1, f32 fparg2) {
    D_004162AC = fparg0;
    D_004162B0 = fparg1;
    D_004162B4 = fparg2;
    D_004162B8 = 0.5f * fparg0;
}
