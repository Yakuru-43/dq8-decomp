// range: 0x340530 0x340540
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00340530(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 9);
}
