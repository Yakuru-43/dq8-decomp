// range: 0x2EEB30 0x2EEB50
// auto: m2c, verified byte-exact
#include "common.h"

void func_002EEB30(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = M2C_FIELD(arg0, s32 *, 0x104);
    *arg2 = M2C_FIELD(arg0, s32 *, 0x108);
}
