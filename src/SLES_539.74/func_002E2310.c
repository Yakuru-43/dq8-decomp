// range: 0x2E2310 0x2E2330
// auto: m2c, verified byte-exact
#include "common.h"

void func_002E2310(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0x9C);
    *arg2 = M2C_FIELD(arg0, s32 *, 0xA0);
}
