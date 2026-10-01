// range: 0x311A40 0x311A90
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014E860();                            /* extern */
M2C_UNK func_0018DCB0(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_00311A40(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_0014E860();
    func_0018DCB0(arg0, arg1, arg2);
    M2C_FIELD(arg0, void **, 0x58) = arg0;
}
