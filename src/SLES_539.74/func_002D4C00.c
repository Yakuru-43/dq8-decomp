// range: 0x2D4C00 0x2D4C30
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_002D7630();                              /* extern */

void func_002D4C00(s32 arg0, s32 arg1, s16 arg2) {
    char *temp_v0;

    temp_v0 = func_002D7630();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 6) = arg2;
    }
}
