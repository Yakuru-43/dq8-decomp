// range: 0x22B530 0x22B580
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00164500(M2C_UNK *, s32);                  /* extern */
extern s32 D_003E0AE0;
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

s32 func_0022B530(s32 arg0) {
    if (func_00164500(&D_003FAFB0, arg0) != 0) {
        D_003E0AE0 |= arg0;
        return 1;
    }
    return 0;
}
