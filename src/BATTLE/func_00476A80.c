// range: 0x476A80 0x476AC0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00476B00();                            /* extern */
extern M2C_UNK D_3DF200 __attribute__((section(".data")));

M2C_UNK **func_00476A80(M2C_UNK **arg0) {
    func_00476B00();
    *arg0 = &D_3DF200;
    return arg0;
}
