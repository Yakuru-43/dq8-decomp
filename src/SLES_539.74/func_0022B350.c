// range: 0x22B350 0x22B3C0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00164100(M2C_UNK *, s32);                  /* extern */
M2C_UNK func_00307690(M2C_UNK);                     /* extern */
extern s32 D_003DFC1C;
extern s32 D_003DFC24;
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

s32 func_0022B350(s32 arg0) {
    if (func_00164100(&D_003FAFB0, arg0) == 0) {
        return 0;
    }
    if (arg0 & (D_003DFC1C | D_003DFC24 | 0x204)) {
        func_00307690(0);
    }
    return 1;
}
