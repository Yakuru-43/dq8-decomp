// range: 0x1677E0 0x167820
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00166AE0();                            /* extern */

void func_001677E0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x10C) != 0) {
        func_00166AE0();
    }
}
