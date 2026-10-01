// range: 0x37D6D0 0x37D700
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00263CF0();                                /* extern */
M2C_UNK func_00263ED0();                            /* extern */
M2C_UNK func_002F6630(s32, M2C_UNK);                /* extern */

void func_0037D6D0(void) {
    func_002F6630(func_00263CF0(), 0xB);
    func_00263ED0();
}
