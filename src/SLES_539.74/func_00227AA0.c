// range: 0x227AA0 0x227AE0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D34C0();                                /* extern */
M2C_UNK func_002D7970(s32);                         /* extern */
M2C_UNK func_002D7B00(s32);                         /* extern */

void func_00227AA0(void) {
    s32 temp_v0;

    temp_v0 = func_002D34C0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002D7970(temp_v0);
    func_002D7B00(temp_v0);
}
