// range: 0x18C5E0 0x18C640
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0016A4A0();                                /* extern */
void *func_0016D5B0(void *, s32);                   /* extern */
M2C_UNK func_0018D2C0(void *, void *);              /* extern */

s32 func_0018C5E0(void *arg0) {
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = func_0016A4A0();
    temp_v0_2 = func_0016D5B0(arg0, temp_v0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s32 *, 0x4F0) = (s32) M2C_FIELD(arg0, s32 *, 0x6410);
        func_0018D2C0(arg0, temp_v0_2);
    }
    return temp_v0;
}
