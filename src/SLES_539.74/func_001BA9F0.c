// range: 0x1BA9F0 0x1BAA20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001BA9F0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = 0;
    }
    return 1;
}
