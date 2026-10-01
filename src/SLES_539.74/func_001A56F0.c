// range: 0x1A56F0 0x1A5720
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001AB9B0(s32, s32, s32);               /* extern */

s32 func_001A56F0(void *arg0, void *arg1) {
    func_001AB9B0(M2C_FIELD(arg1, s32 *, 0x40), M2C_FIELD(arg1, s32 *, 0x68), M2C_FIELD(arg0, s32 *, 0x20));
    return 0;
}
