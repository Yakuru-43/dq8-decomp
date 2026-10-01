// range: 0x340760 0x340770
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340760(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13) == 0x35;
}
