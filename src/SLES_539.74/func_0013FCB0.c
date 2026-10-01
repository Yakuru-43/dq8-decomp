// range: 0x13FCB0 0x13FCF0
// auto: m2c, verified byte-exact
#include "common.h"

f32 func_0013D340(s32);                             /* extern */

f32 func_0013FCB0(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xF20);
    if (temp_v0 != 0) {
        return func_0013D340(temp_v0 + 0x170);
    }
    return 0.0f;
}
