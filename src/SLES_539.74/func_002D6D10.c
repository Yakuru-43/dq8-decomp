// range: 0x2D6D10 0x2D6D40
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
M2C_UNK func_002DE510(s32);                         /* extern */

void func_002D6D10(void) {
    s32 temp_v0;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_002DE510(temp_v0);
}
