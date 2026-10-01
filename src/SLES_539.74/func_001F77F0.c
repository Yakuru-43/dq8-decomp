// range: 0x1F77F0 0x1F7840
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001F77F0(void *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0x15F0))) {
        return M2C_FIELD(arg0, s32 *, 0x15F4) + (arg1 * 0xD0);
    }
    return 0;
}
