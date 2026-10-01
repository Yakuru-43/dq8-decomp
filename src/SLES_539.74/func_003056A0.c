// range: 0x3056A0 0x3056D0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167A80();                                /* extern */
M2C_UNK func_00371BB0(s32, M2C_UNK);                /* extern */

void func_003056A0(void) {
    func_00371BB0(func_00167A80(), 2);
}
