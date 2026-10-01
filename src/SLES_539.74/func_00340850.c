// range: 0x340850 0x340860
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00340850(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 4);
}
