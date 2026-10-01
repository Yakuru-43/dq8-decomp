// range: 0x310800 0x310830
// auto: m2c, verified byte-exact
#include "common.h"

void func_00310800(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 4);
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_a1, s32 *, 0x1C8) = (s32) (M2C_FIELD(temp_a1, s32 *, 0x1C8) & ~1);
    }
}
