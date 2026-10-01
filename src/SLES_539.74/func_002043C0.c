// range: 0x2043C0 0x2043F0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00308D10(s32);                         /* extern */

void func_002043C0(s32 arg0, s32 arg1) {
    if ((arg1 > 0) && (arg1 < 0x200)) {
        func_00308D10(arg0 + 0xA78);
    }
}
