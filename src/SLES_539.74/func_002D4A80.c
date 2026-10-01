// range: 0x2D4A80 0x2D4AB0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_002D76A0();                              /* extern */

void func_002D4A80(void) {
    void *temp_v0;

    temp_v0 = func_002D76A0();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v0, s32 *, 0) = -1;
    }
}
