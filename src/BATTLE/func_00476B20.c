// range: 0x476B20 0x476B60
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00476B00();                            /* extern */
extern M2C_UNK D_3DF1A0 __attribute__((section(".data")));

M2C_UNK **func_00476B20(M2C_UNK **arg0) {
    func_00476B00();
    *arg0 = &D_3DF1A0;
    return arg0;
}
