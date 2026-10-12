// range: 0x276DC0 0x276E00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00159630(s32, s32);                    /* extern */
char *func_0015F490();                              /* extern */

void func_00276DC0(char *arg0) {

    if (!(M2C_FIELD(arg0, s32 *, 8) != 0)) {
        return;
    }

    func_00159630(M2C_FIELD(func_0015F490(), s32 *, 0x3B90), M2C_FIELD(arg0, s32 *, 4));
}
