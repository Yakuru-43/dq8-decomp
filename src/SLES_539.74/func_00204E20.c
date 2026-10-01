// range: 0x204E20 0x204E70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00204E70(s32, M2C_UNK);                    /* extern */
s32 func_00204EA0();                                /* extern */

s32 func_00204E20(s32 arg0, M2C_UNK arg1) {
    s32 temp_s0;

    temp_s0 = func_00204EA0();
    return temp_s0 - func_00204E70(arg0, arg1);
}
