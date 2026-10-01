// range: 0x465150 0x4651B0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CC0();                                  /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_372E60(s32, M2C_UNK, M2C_UNK);         /* extern */

void func_00465150(s32 arg0) {
    func_372E60(func_201CC0(), 3, 1);
    func_2D38E0(arg0, 0x2745, 1, -1);
    func_2D38E0(arg0, 0x17A2, 1, -1);
}
