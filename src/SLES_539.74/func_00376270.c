// range: 0x376270 0x3762B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 *func_001813D0();                               /* extern */
M2C_UNK func_00376130();                            /* extern */

void func_00376270(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = func_001813D0();
    if (temp_v0 != NULL) {
        *temp_v0 = arg0;
        func_00376130();
    }
}
