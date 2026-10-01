// range: 0x4656A0 0x4656D0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CC0();                                  /* extern */
M2C_UNK func_372E60(s32, M2C_UNK, M2C_UNK);         /* extern */

s32 func_004656A0(void) {
    func_372E60(func_201CC0(), 2, 1);
    return 1;
}
