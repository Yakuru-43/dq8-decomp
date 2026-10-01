// range: 0x1A4DC0 0x1A4DF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001ABD90(f32, s32, s32);               /* extern */

s32 func_001A4DC0(void *arg0, void *arg1) {
    func_001ABD90(M2C_FIELD(arg0, f32 *, 0x20), M2C_FIELD(arg1, s32 *, 0x40), M2C_FIELD(arg1, s32 *, 0x68));
    return 0;
}
