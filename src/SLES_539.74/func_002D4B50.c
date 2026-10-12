// range: 0x2D4B50 0x2D4BA0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_002D4150();                                /* extern */
char *func_002DE140(s32);                           /* extern */

void func_002D4B50(s32 arg0, s32 arg1, s16 arg2) {
    s32 temp_v0;
    char *temp_v0_2;

    temp_v0 = func_002D4150();

    if (!(temp_v0 != 0)) {
        return;
    }

    temp_v0_2 = func_002DE140(temp_v0);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s16 *, 8) = arg2;
    }
}
