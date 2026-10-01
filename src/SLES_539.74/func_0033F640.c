// range: 0x33F640 0x33F6B0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0033F820();                            /* extern */
M2C_UNK func_0033F930(s32, s32, M2C_UNK);           /* extern */
s32 func_0036F000(M2C_UNK *, s32, s32 *);           /* extern */
extern M2C_UNK D_003D2FD0 __attribute__((section(".data")));

void func_0033F640(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;

    func_0033F820();
    if (func_0036F000(&D_003D2FD0, arg0, &sp3C) != 0) {
        func_0033F930(arg0, sp3C, arg1);
    }
}
