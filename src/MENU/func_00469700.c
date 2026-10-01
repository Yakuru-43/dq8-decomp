// range: 0x469700 0x469750
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_201CC0();                                  /* extern */
M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
M2C_UNK func_372E60(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_37CEE0(M2C_UNK);                       /* extern */
M2C_UNK func_37CF20(M2C_UNK);                       /* extern */

s32 func_00469700(void) {
    func_22AB50(0);
    func_37CEE0(0);
    func_37CF20(-1);
    func_372E60(func_201CC0(), 0xF, 1);
    return 1;
}
