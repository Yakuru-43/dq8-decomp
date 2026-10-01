// range: 0x1F0A10 0x1F0A30
// auto: m2c draft, verified byte-exact
#include "common.h"

extern f32 D_003DFCD8;
extern f32 D_003DFCDC;
extern f32 D_003DFCE0;
extern f32 D_003DFCE4;
extern f32 D_003DFCE8;

void func_001F0A10(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    D_003DFCDC = fparg0;
    D_003DFCE0 = fparg1;
    D_003DFCE4 = fparg2;
    D_003DFCE8 = fparg3;
    D_003DFCD8 = fparg4;
}
