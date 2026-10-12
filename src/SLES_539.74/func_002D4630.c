// range: 0x2D4630 0x2D4660
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_002D4660(s32);                         /* extern */

void func_002D4630(void) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002D4660(temp_v0 + 0x30);
}
