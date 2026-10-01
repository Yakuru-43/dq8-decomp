// range: 0x2D5300 0x2D5360
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_002D4150();                              /* extern */
char *func_002DE240(char *);                        /* extern */

void func_002D5300(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    char *temp_v0;
    char *temp_v0_2;

    temp_v0 = func_002D4150();
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x2C) != 0)) {
        temp_v0_2 = func_002DE240(temp_v0);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s16 *, 0) = arg2;
            M2C_FIELD(temp_v0_2, s16 *, 2) = arg3;
        }
    }
}
