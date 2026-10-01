// range: 0x33F720 0x33F790
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
M2C_UNK func_0033F860();                            /* extern */
M2C_UNK func_0033FA50(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_003D3010 __attribute__((section(".data")));

void func_0033F720(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;

    func_0033F860();
    if (func_001629F0(&D_003D3010, arg0, &sp3C) != 0) {
        func_0033FA50(arg0, sp3C, arg1);
    }
}
