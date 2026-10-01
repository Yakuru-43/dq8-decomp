// range: 0x204330 0x204360
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00204330(s32 arg0, s32 arg1) {
    if ((arg1 > 0) && (arg1 < 0x185)) {
        return M2C_FIELD((arg1 + arg0), u8 *, 0xAB8);
    }
    return 0U;
}
