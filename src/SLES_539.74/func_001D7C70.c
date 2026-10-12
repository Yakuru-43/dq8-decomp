// range: 0x1D7C70 0x1D7CE0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00168160();                                /* extern */
M2C_UNK func_0016A430(s32, s32);                    /* extern */
s32 func_001814D0();                                /* extern */
M2C_UNK func_001DB1A0(s32, s32, M2C_UNK);           /* extern */
char *func_0033A090(s32, s32);                      /* extern */

void func_001D7C70(s32 arg0) {
    s32 temp_v0;
    char *temp_v0_2;

    temp_v0 = func_00168160();

    if (!(temp_v0 != 0)) {
        return;
    }

    temp_v0_2 = func_0033A090(temp_v0 + 0x6B34, arg0);
    if (temp_v0_2 != NULL) {
        func_0016A430(temp_v0, M2C_FIELD(temp_v0_2, s32 *, 0x180));
    }
    func_001DB1A0(func_001814D0(), temp_v0, 1);
}
