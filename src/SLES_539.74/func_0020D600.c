// range: 0x20D600 0x20D660
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
s32 func_002231D0(M2C_UNK, s32, s32);               /* extern */
extern M2C_UNK D_003C77F0 __attribute__((section(".data")));
extern s32 D_003E08BC;

void func_0020D600(s32 arg0, M2C_UNK arg1) {
    s32 sp3C;

    if (func_001629F0(&D_003C77F0, arg0, &sp3C) != 0) {
        D_003E08BC = func_002231D0(arg1, arg0, sp3C);
    }
}
