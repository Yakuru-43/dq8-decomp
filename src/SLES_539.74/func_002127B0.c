// range: 0x2127B0 0x2127E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00166700();                            /* extern */

void func_002127B0(void *arg0) {
    func_00166700();
    M2C_FIELD(arg0, s32 *, 0xC) = 0x3F800000;
}
