// range: 0x212100 0x212130
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780();                                /* extern */
extern f32 D_003DFD08;

s32 func_00212100(void) {
    D_003DFD08 = func_00166780();
    return 1;
}
