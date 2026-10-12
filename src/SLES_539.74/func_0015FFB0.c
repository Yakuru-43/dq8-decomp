// range: 0x15FFB0 0x160030
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 iPollSema(s32);                                 /* extern */
M2C_UNK iSignalSema(s32);                           /* extern */
extern s32 D_003DFBB8;
extern s32 D_003E0328;
extern s32 D_003E032C;
extern s32 D_003E0338;

void func_0015FFB0(void) {

    if (!((D_003E0328 != 0) && (D_003E032C != 0) && (D_003DFBB8 >= 0))) {
        return;
    }

    if (D_003E0338 != 0) {
        return;
    }
    if (iPollSema(D_003DFBB8) < 0) {
        iSignalSema(D_003DFBB8);
    }
}
