// range: 0x350170 0x3501B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0();                    /* extern */

void func_00350170(s32 arg0, s32 arg1) {
    func_001340C0();
    func_001340C0(arg0 + 0x20, arg1 + 0x20);
}
