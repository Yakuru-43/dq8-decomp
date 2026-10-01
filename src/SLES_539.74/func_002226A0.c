// range: 0x2226A0 0x2226E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_002224F0(s32);                         /* extern */
M2C_UNK func_002226E0(s32);                         /* extern */
M2C_UNK func_002F6960();                            /* extern */

s32 func_002226A0(s32 arg0) {
    func_002F6960();
    func_002226E0(arg0 + 0x1F18);
    func_002224F0(arg0);
    return arg0;
}
