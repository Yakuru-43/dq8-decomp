// range: 0x37A7D0 0x37A840
// auto: m2c draft, verified byte-exact
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_00181420();                                /* extern */
s32 func_00203FD0(s32, M2C_UNK);                    /* extern */
extern s16 D_003E1528;
extern s16 D_003E152C;

void func_0037A7D0(void) {
    s32 temp_lo;

    temp_lo = (s32) (func_00203FD0(func_00181420(), 4) - 1) / 12;
    D_003E152C = (s16) temp_lo;
    if (D_003E152C < 0) {
        D_003E152C = 0;
    }
    if (D_003E152C < D_003E1528) {
        D_003E1528 = D_003E152C;
    }
}
