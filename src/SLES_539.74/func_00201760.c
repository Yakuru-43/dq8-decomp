// range: 0x201760 0x201780
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00201760(void *arg0, s32 *arg1) {
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(arg0, s32 *, 0x64);
    }
    return M2C_FIELD(arg0, s32 *, 0x68);
}
