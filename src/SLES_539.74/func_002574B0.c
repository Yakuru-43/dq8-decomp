// range: 0x2574B0 0x2574F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002574B0(void *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s16 *, 4))) {
        return M2C_FIELD(arg0, s32 *, 0) + (arg1 * 0xC);
    }
    return 0;
}
