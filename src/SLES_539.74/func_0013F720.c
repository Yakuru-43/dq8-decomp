// range: 0x13F720 0x13F770
// auto: m2c, verified byte-exact
#include "common.h"

void *func_0014E130(s32, M2C_UNK);                  /* extern */

s32 func_0013F720(void *arg0) {
    void *temp_v0;

    M2C_FIELD(arg0, s32 *, 4) = 0;
    temp_v0 = func_0014E130(M2C_FIELD(arg0, s32 *, 0), 1);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x60000000;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, s32 *, 8) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xC) = 0;
    return M2C_FIELD(arg0, s32 *, 0xF0);
}
