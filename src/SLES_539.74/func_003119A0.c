// range: 0x3119A0 0x3119D0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0014E030(s32);                         /* extern */
s32 func_00223710();                                /* extern */

void func_003119A0(void) {
    s32 temp_v0;

    temp_v0 = func_00223710();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_0014E030(temp_v0);
}
