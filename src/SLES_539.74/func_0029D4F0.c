// range: 0x29D4F0 0x29D520
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0029D430();                            /* extern */

s32 func_0029D4F0(void *arg0) {
    func_0029D430();
    return M2C_FIELD(arg0, s32 *, 0x5C0) + M2C_FIELD(arg0, s32 *, 0x5C4);
}
