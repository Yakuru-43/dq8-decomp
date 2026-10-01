// range: 0x310830 0x310850
// auto: m2c, verified byte-exact
#include "common.h"

void func_00310830(void *arg0) {
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 4);
    if (temp_a0 != NULL) {
        M2C_FIELD(temp_a0, s32 *, 0x1C8) = (s32) (M2C_FIELD(temp_a0, s32 *, 0x1C8) | 1);
    }
}
