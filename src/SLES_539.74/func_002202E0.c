// range: 0x2202E0 0x220310
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00220340();                            /* extern */

void func_002202E0(void *arg0) {
    func_00220340();
    M2C_FIELD(arg0, s8 *, 1) = 1;
}
