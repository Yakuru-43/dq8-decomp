// range: 0x20CC40 0x20CC70
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0020CC40(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((arg1 >= 0) && (arg1 < 2)) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x5874);
        M2C_FIELD(arg0, s32 *, 0x5874) = arg1;
        return temp_v0;
    }
    return M2C_FIELD(arg0, s32 *, 0x5874);
}
