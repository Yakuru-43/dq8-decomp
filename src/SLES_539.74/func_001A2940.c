// range: 0x1A2940 0x1A2980
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_00143190(s32);                             /* extern */
s32 func_0015F490();                                /* extern */
extern f32 D_003DF4B4;
extern s32 D_003E0664;
extern f32 D_00411DF0 __attribute__((section(".data")));

void func_001A2940(s32 arg0) {
    D_003E0664 = arg0;
    D_00411DF0 = (180.0f * func_00143190(func_0015F490())) / D_003DF4B4;
}
