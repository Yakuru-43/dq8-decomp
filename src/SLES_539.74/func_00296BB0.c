// range: 0x296BB0 0x296BD0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00296BB0(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x58C);
    M2C_FIELD(temp_a1, s32 *, 0xF0) = (s32) M2C_FIELD(temp_a1, s16 *, 0x10);
    M2C_FIELD(temp_a1, s32 *, 0xF4) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x58C), s16 *, 0x12);
    return 1;
}
