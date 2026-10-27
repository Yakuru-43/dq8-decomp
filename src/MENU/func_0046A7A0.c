// range: 0x46A7A0 0x46A820
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0046A7A0(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_2D34C0();
    if (arg0 != 0) {
        func_2D38E0(temp_s0, 0x4A5, 1, -1);
        return;
    }
    func_2D38E0(temp_s0, 0x4A5, 0, -1);
    func_2D38E0(temp_s0, 0x2733, 0, -1);
}
