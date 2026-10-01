// range: 0x1BFED0 0x1BFF20
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00305520(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK D_00402010 __attribute__((section(".data")));

s32 func_001BFED0(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_00305520(&D_00402010, 0xD);
    if (M2C_FIELD(arg0, s32 *, 0) == 3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
