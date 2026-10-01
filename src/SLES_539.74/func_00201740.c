// range: 0x201740 0x201760
// auto: m2c, verified byte-exact
#include "common.h"

s16 func_00201740(void *arg0, s32 *arg1) {
    if (arg1 != NULL) {
        *arg1 = (s32) M2C_FIELD(arg0, s16 *, 0x6C);
    }
    return M2C_FIELD(arg0, s16 *, 0x6E);
}
