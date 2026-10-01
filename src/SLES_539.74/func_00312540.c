// range: 0x312540 0x312550
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00220070(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_00415A40 __attribute__((section(".data")));

void func_00312540(s32 arg0) {
    func_00220070(&D_00415A40, arg0);
}
