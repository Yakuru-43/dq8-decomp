// range: 0x2B0D50 0x2B0DE0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, char *);                 /* extern */
u32 func_001341D8(char *);                          /* extern */

void func_002B0D50(s32 arg0, s32 arg1, char *arg2) {

    if (!((arg1 >= 0) && (arg1 < 2) && (arg2 != NULL))) {
        return;
    }

    if (func_001341D8(arg2) >= 0x20U) {
        M2C_FIELD(arg2, s8 *, 0x1F) = 0;
    }
    func_001340C0(arg0 + (arg1 << 5), arg2);
}
