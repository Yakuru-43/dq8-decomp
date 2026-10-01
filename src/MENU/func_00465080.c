// range: 0x465080 0x4650C0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, s32, M2C_UNK);    /* extern */

void func_00465080(s32 arg0) {
    func_2D38E0(func_2D34C0(), 0x2733, arg0 != 0, -1);
}
