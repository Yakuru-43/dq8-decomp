// range: 0x212740 0x212790
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_00166780(s32);                             /* extern */
s32 func_00212790();                                /* extern */
extern void *D_003E0944;

s32 func_00212740(s32 arg0) {
    if (func_00212790() != 0) {
        M2C_FIELD(D_003E0944, f32 *, 8) = func_00166780(arg0);
        return 1;
    }
    return 1;
}
