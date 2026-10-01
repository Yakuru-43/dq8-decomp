// range: 0x2D7060 0x2D70A0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_002D4150();                              /* extern */

void func_002D7060(s32 arg0, s32 arg1, s32 arg2) {
    char *temp_v0;

    temp_v0 = func_002D4150();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0x24) = (f32) arg2;
    }
}
