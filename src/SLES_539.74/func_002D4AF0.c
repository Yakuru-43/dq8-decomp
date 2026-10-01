// range: 0x2D4AF0 0x2D4B30
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_002D76A0();                              /* extern */

void func_002D4AF0(s32 arg0, s32 arg1, s32 arg2) {
    char *temp_v0;

    temp_v0 = func_002D76A0();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v0, s32 *, 0) = arg2;
    }
}
