// range: 0x1EE300 0x1EE340
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001EE340();                /* extern */

void func_001EE300(s32 arg0, s32 arg1, M2C_UNK arg2) {
    func_001EE340();
    func_001EE340(arg0 + 0x10, arg2);
}
