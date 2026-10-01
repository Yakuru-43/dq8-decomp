// range: 0x276E50 0x276E70
// auto: m2c, verified byte-exact
#include "common.h"

void func_00276E50(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = *arg2 * M2C_FIELD(arg0, f32 *, 0x4C);
}
