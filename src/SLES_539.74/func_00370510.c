// range: 0x370510 0x370590
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, s64);                /* extern */
extern M2C_UNK D_003D5020 __attribute__((section(".data")));
extern s8 D_003E0080;

void func_00370510(s64 arg0) {
    D_003E0080 = (s8) arg0;
    if (((s64) (arg0 << 0x38) >> 0x38) < 0) {
        D_003E0080 = 0;
        DebugPrintf(&D_003D5020, arg0);
    }
    if (D_003E0080 >= 6) {
        D_003E0080 = 5;
        DebugPrintf(&D_003D5020, arg0);
    }
}
