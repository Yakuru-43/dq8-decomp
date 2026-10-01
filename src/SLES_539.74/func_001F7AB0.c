// range: 0x1F7AB0 0x1F7AC0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001F7AB0(void *arg0, s32 *arg1) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0x4E4);
    return M2C_FIELD(arg0, s32 *, 0x4E8);
}
