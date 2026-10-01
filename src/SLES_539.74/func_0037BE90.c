// range: 0x37BE90 0x37BEC0
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_0037BE90(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 4)) {
        return M2C_FIELD((arg1 + arg0), u8 *, 0x10);
    }
    return 0U;
}
