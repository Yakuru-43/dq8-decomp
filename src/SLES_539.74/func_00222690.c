// range: 0x222690 0x2226A0
// auto: m2c, verified byte-exact
#include "common.h"

void func_00222690(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x174) = 0xBF800000;
    M2C_FIELD(arg0, s32 *, 0x178) = 0xBF800000;
}
