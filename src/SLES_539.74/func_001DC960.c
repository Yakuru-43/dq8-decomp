// range: 0x1DC960 0x1DC9C0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00188630(s32);                             /* extern */
extern void *D_003E0734;

s32 func_001DC960(void *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 != 1) {
        return 0;
    }
    temp_v0 = func_00188630(M2C_FIELD(D_003E0734, s32 *, 4));
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
