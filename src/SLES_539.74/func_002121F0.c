// range: 0x2121F0 0x212270
#include "common.h"

f32 func_00166780();                                /* extern */
f32 func_0013BCA0(f32);                             /* extern */
s32 func_001667C0();                                /* extern */
extern f32 D_003DF4B8;
extern char *D_003E0944;

s32 func_002121F0(M2C_UNK arg0) {
    s32 mode;

    mode = M2C_FIELD(arg0, s32 *, 0);
    switch (mode) {
    case 1:
        M2C_FIELD(D_003E0944, f32 *, 0xC) =
            func_0013BCA0(D_003DF4B8 * (f32)func_001667C0());
        break;
    case 2:
        M2C_FIELD(D_003E0944, f32 *, 0xC) = func_00166780();
        break;
    default:
        break;
    }
    return 1;
}
