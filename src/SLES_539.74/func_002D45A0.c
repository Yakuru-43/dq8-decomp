// range: 0x2D45A0 0x2D45D0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_00375A70(s32);                         /* extern */

void func_002D45A0(void) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_00375A70(temp_v0 + 0x30);
}
