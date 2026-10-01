// range: 0x340420 0x340460
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_002B8330(u8);                              /* extern */

s32 func_00340420(void *arg0, s32 *arg1) {
    *arg1 = func_002B8330(M2C_FIELD(arg0, u8 *, 0x13));
    return *arg1 > 0;
}
