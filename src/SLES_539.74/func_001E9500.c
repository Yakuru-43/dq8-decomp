// range: 0x1E9500 0x1E9570
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001007A0(void *);                      /* extern */
M2C_UNK func_001E9570();                            /* extern */

void *func_001E9500(void *arg0, s64 arg1) {
    void *temp_a0;

    if (arg0 != NULL) {
        func_001E9570();
        temp_a0 = M2C_FIELD(arg0, void **, 8);
        if (temp_a0 != NULL) {
            func_001007A0(temp_a0);
        }
        if (((s64) (arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}
