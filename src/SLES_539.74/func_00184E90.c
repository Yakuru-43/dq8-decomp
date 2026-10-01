// range: 0x184E90 0x184F10
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0016D5B0(void *, s32);                     /* extern */
s32 func_001822C0(void *);                          /* extern */
M2C_UNK func_001EA0A0(s32, s32, M2C_UNK);           /* extern */
s32 func_002C5F50();                                /* extern */

s32 func_00184E90(void **arg0) {
    s32 temp_v0;
    void *temp_s0;

    temp_s0 = *arg0;
    if (temp_s0 == NULL) {
        return 0;
    }
    if (func_002C5F50() == 0) {
        temp_v0 = func_0016D5B0(temp_s0, M2C_FIELD(temp_s0, s32 *, 0x44B0));
        if (temp_v0 != 0) {
            func_001EA0A0(temp_v0, func_001822C0(temp_s0), 0);
        }
    }
    return 0;
}
