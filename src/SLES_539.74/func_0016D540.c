// range: 0x16D540 0x16D580
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0016B920();                              /* extern */

void func_0016D540(s32 arg0, s32 arg1, s32 arg2) {
    char *temp_v0;

    temp_v0 = func_0016B920();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x28) = arg2;
        M2C_FIELD(temp_v0, s32 *, 0x2C) = 1;
    }
}
