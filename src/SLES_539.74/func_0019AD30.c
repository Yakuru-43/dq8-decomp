// range: 0x19AD30 0x19AD50
// auto: m2c, verified byte-exact
#include "common.h"

void func_0019AD30(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x28);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, s32 *, 0x50) = arg1;
    }
}
