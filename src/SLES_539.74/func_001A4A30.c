// range: 0x1A4A30 0x1A4A60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001735C0(s32, s32, M2C_UNK);           /* extern */

s32 func_001A4A30(void *arg0) {
    func_001735C0(M2C_FIELD(arg0, s32 *, 0x20), M2C_FIELD(arg0, s32 *, 0x24), 0);
    return 0;
}
