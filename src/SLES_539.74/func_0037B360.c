// range: 0x37B360 0x37B390
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00376460(s32);                         /* extern */
M2C_UNK func_003768A0();                            /* extern */

s32 func_0037B360(s32 arg0) {
    func_003768A0();
    func_00376460(arg0);
    return arg0;
}
