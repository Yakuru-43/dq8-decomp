// range: 0x4671D0 0x467250
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D4BA0(s32, M2C_UNK, s32, M2C_UNK);    /* extern */
s32 func_2D53A0(s32, M2C_UNK, s32);                 /* extern */
M2C_UNK func_2D7060(s32, M2C_UNK, s32);             /* extern */

void func_004671D0(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_2D34C0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_2D4BA0(temp_v0, 0x590, func_2D53A0(temp_v0, 0x58F, arg0) + 0x18, 0);
    func_2D7060(temp_v0, 0x590, (arg0 * 0x19) + 0xD);
}
