// range: 0x2020F0 0x202120
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00181420();                                /* extern */
M2C_UNK func_00206080(s32, s32);                    /* extern */

void func_002020F0(s32 arg0) {
    func_00206080(func_00181420(), arg0);
}
