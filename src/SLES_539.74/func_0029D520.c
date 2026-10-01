// range: 0x29D520 0x29D560
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0029D430();                            /* extern */

s32 func_0029D520(void *arg0) {
    func_0029D430();
    return M2C_FIELD(arg0, s32 *, 0x5D4) + (M2C_FIELD(arg0, s32 *, 0x5D0) + (M2C_FIELD(arg0, s32 *, 0x5C8) + M2C_FIELD(arg0, s32 *, 0x5CC)));
}
