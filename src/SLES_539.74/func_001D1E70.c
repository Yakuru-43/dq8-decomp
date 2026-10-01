// range: 0x1D1E70 0x1D1EB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0();                         /* extern */

void func_001D1E70(char *arg0, s32 arg1, s32 arg2) {
    func_001340C0(arg0 + 0xC);
    M2C_FIELD(arg0, s32 *, 8) = arg2;
}
