// range: 0x191F90 0x191FF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(s32, M2C_UNK);                /* extern */
u32 func_001341D8(M2C_UNK);                         /* extern */

void func_00191F90(s32 arg0, M2C_UNK arg1) {
    if (func_001341D8(arg1) < 0x10U) {
        func_001340C0(arg0, arg1);
    }
}
