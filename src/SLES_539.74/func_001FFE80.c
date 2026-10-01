// range: 0x1FFE80 0x1FFEC0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001575A0();                            /* extern */

void *func_001FFE80(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = -1;
    func_001575A0();
    return arg0;
}
