// range: 0x18C5A0 0x18C5E0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0016D5B0();                              /* extern */

void func_0018C5A0(void) {
    void *temp_v0;

    temp_v0 = func_0016D5B0();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x520) = 0x43480000;
        M2C_FIELD(temp_v0, s32 *, 0x524) = 0x43820000;
        M2C_FIELD(temp_v0, s32 *, 0x528) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x52C) = 0x40000000;
    }
}
