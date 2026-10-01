// range: 0x18F230 0x18F290
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0018F3F0();                              /* extern */
extern M2C_UNK D_0040FAB0 __attribute__((section(".data")));

M2C_UNK *func_0018F230(s32 arg0, s32 *arg1) {
    char *temp_v0;

    if (arg1 != NULL) {
        *arg1 = 0;
    }
    temp_v0 = func_0018F3F0();
    if (temp_v0 != NULL) {
        if (arg1 != NULL) {
            *arg1 = M2C_FIELD(temp_v0, s32 *, 8);
        }
        return M2C_FIELD(temp_v0, M2C_UNK **, 0);
    }
    return &D_0040FAB0;
}
