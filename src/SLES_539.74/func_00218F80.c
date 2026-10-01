// range: 0x218F80 0x219040
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0021BCC0();                                /* extern */
M2C_UNK func_00220030(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_00220080(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */
s32 func_002205C0(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_00220750(s32, M2C_UNK);                /* extern */
M2C_UNK func_0022AB50(M2C_UNK);                     /* extern */
extern M2C_UNK D_00415A40 __attribute__((section(".data")));
extern s32 D_00415D48 __attribute__((section(".data")));
extern s32 D_00415D50 __attribute__((section(".data")));

s32 func_00218F80(void *arg0) {
    if (func_002205C0(D_00415D48, 0, 0) == 1) {
        func_0022AB50(0);
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
        func_00220750(D_00415D48, 0);
        if (func_0021BCC0() == 1) {
            func_00220030(&D_00415A40, 0);
            func_00220080(&D_00415A40, D_00415D50, 0, -1);
        }
        return 0;
    }
    return 0;
}
