// range: 0x46A480 0x46A4C0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00469F40(s32, s32);                    /* extern */
s32 func_0046CE90();                                /* extern */
s32 func_0046D0C0();                                /* extern */

void func_0046A480(void) {
    s32 temp_s0;

    temp_s0 = func_0046D0C0();
    func_00469F40(temp_s0, func_0046CE90());
}
