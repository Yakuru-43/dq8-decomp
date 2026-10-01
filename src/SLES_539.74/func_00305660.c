// range: 0x305660 0x3056A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00167A80();                                /* extern */
M2C_UNK func_00371900(s32, M2C_UNK, s32);           /* extern */

void func_00305660(s32 arg0) {
    func_00371900(func_00167A80(), 2, arg0);
}
