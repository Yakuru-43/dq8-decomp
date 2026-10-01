// range: 0x24F400 0x24F440
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00250940();                            /* extern */

void *func_0024F400(void *arg0) {
    func_00250940();
    M2C_FIELD(arg0, s32 *, 0x7C) = -1;
    M2C_FIELD(arg0, s8 *, 0x80) = 0;
    M2C_FIELD(arg0, s16 *, 0x82) = 0;
    return arg0;
}
