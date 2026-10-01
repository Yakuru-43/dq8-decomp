// range: 0x1D01A0 0x1D0200
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001643E0(M2C_UNK *);                       /* extern */
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

s32 func_001D01A0(void *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 <= 0) {
        return 0;
    }
    temp_v0 = func_001643E0(&D_003FAFB0);
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
