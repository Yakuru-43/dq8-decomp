// range: 0x35F890 0x35F8F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
void *func_002B2050(s32, s32);                      /* extern */

void func_0035F890(void *arg0) {
    void *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = func_002B2050(func_001814D0() + 0x5890, M2C_FIELD(arg0, s32 *, 0));
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0x6E);
            M2C_FIELD(temp_v0, s8 *, 4) = (s8) (M2C_FIELD(arg0, s32 *, 0x68) <= 0);
        }
    }
}
