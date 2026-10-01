// range: 0x3790F0 0x379120
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001FF770(s32);                             /* extern */
s32 func_00201C90();                                /* extern */
M2C_UNK func_00305950(s32);                         /* extern */

s32 func_003790F0(void) {
    func_00305950(func_001FF770(func_00201C90()));
    return 1;
}
