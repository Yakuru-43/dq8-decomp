// range: 0x306880 0x3068E0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0014EA80(M2C_UNK);                         /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
M2C_UNK func_003063C0(s32, s32, M2C_UNK);           /* extern */
extern M2C_UNK D_003D0190 __attribute__((section(".data")));
extern s32 D_003E111C;

void func_00306880(s32 arg0) {
    s32 sp2C;

    D_003E111C = func_0014EA80(0x5100);
    if (func_001629F0(&D_003D0190, arg0, &sp2C) != 0) {
        func_003063C0(arg0, sp2C, 0);
    }
}
