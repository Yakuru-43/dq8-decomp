// range: 0x25A0B0 0x25A150
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, s32);               /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
s32 func_00192080(s32, s32);                        /* extern */
extern M2C_UNK D_003C95B8 __attribute__((section(".data")));
extern s32 D_003E0C48;
extern s32 D_003E0C4C;

void func_0025A0B0(s32 arg0, s32 arg1) {
    s32 sp3C;
    s32 temp_v0;

    D_003E0C48 = 0;

    if (!((arg0 != 0) && (arg1 != 0))) {
        return;
    }

    if (func_001629F0(&D_003C95B8, arg0, &sp3C) != 0) {
        temp_v0 = func_00192080(arg1, (sp3C >> 4) + 1);
        D_003E0C4C = temp_v0;
        func_00130FD0(temp_v0, arg0, sp3C);
        D_003E0C48 = D_003E0C4C;
    }
}
