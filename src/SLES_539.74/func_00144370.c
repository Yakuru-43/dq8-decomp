// range: 0x144370 0x144380
// auto: m2c, verified byte-exact
#include "common.h"

void func_00144370(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x270);
    M2C_FIELD(temp_v1, s32 *, 0x24) = arg1;
    M2C_FIELD(temp_v1, s32 *, 0x28) = arg2;
}
