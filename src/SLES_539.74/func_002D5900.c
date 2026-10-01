// range: 0x2D5900 0x2D5940
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_002D4150();                              /* extern */

void func_002D5900(s32 arg0, s32 arg1, s8 arg2, s32 arg3) {
    char *temp_v0;

    temp_v0 = func_002D4150();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 *, 0x2A) = arg2;
        M2C_FIELD(temp_v0, s32 *, 0x2C) = arg3;
    }
}
