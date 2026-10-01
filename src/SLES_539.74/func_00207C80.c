// range: 0x207C80 0x207CD0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00207CD0(s32);                             /* extern */
s32 func_0024D8B0();                                /* extern */

s32 func_00207C80(void) {
    s32 temp_v0;

    temp_v0 = func_0024D8B0();
    if ((temp_v0 > 0) && (temp_v0 < 8)) {
        return func_00207CD0(temp_v0);
    }
    return -1;
}
