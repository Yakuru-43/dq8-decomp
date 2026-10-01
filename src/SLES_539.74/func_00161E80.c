// range: 0x161E80 0x161ED0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_00161ED0();                              /* extern */

char *func_00161E80(s32 arg0, s32 arg1, s32 *arg2) {
    char *temp_v0;

    temp_v0 = func_00161ED0();
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg2 != NULL) {
        *arg2 = M2C_FIELD(temp_v0, s32 *, 0x44);
    }
    return temp_v0 + M2C_FIELD(temp_v0, s32 *, 0x40);
}
