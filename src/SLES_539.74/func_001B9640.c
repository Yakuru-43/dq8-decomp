// range: 0x1B9640 0x1B96A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00188630(s32);                             /* extern */
extern s32 D_003E0664;

s32 func_001B9640(void *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 != 1) {
        return 0;
    }
    temp_v0 = func_00188630(D_003E0664);
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
