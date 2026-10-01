// range: 0x33F5D0 0x33F640
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0033F800();                            /* extern */
M2C_UNK func_0033F8A0(s32, s32, M2C_UNK);           /* extern */
s32 func_0036F000(M2C_UNK *, s32, s32 *);           /* extern */
extern M2C_UNK D_003D2FB0 __attribute__((section(".data")));

void func_0033F5D0(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;

    func_0033F800();
    if (func_0036F000(&D_003D2FB0, arg0, &sp3C) != 0) {
        func_0033F8A0(arg0, sp3C, arg1);
    }
}
