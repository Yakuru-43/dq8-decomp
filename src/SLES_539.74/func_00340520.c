// range: 0x340520 0x340530
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00340520(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xA);
}
