// range: 0x23F1E0 0x23F240
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0B24;

s32 func_0023F1E0(void *arg0, s32 arg1) {
    if ((arg1 != 1) && (arg1 != 2)) {
        return 0;
    }
    if (M2C_FIELD(D_003E0B24, s32 *, 8) == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = 0;
    }
    return 1;
}
