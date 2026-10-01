// range: 0x165200 0x165240
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00165150();                            /* extern */

void *func_00165200(void *arg0) {
    func_00165150();
    M2C_FIELD(arg0, s32 *, 0xC8) = -1;
    M2C_FIELD(arg0, s32 *, 0xC4) = -1;
    return arg0;
}
