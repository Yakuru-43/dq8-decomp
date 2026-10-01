// range: 0x167FE0 0x168040
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0015FFB0();                            /* extern */
M2C_UNK iSignalSema(s32);                           /* extern */
extern s32 D_003DFBC4;
extern s8 D_003DFBCC;
extern s8 D_003E036C;
extern s64 D_003E0370;

s32 func_00167FE0(void) {
    if (D_003DFBCC != 0) {
        iSignalSema(D_003DFBC4);
        D_003DFBCC = 0;
    }
    func_0015FFB0();
    if (D_003E036C != 0) {
        D_003E0370 += 1;
    }
    return 0;
}
