// range: 0x30B320 0x30B380
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0030A730(s32);                             /* extern */
M2C_UNK func_00356910(s32, M2C_UNK);                /* extern */

void func_0030B320(s32 arg0, void *arg1) {
    if ((M2C_FIELD(arg1, s32 *, 0x114) != 0) && (func_0030A730(M2C_FIELD(arg1, s32 *, 0x138)) != 0)) {
        func_00356910(arg0, 1);
        return;
    }
    func_00356910(arg0, 0);
}
