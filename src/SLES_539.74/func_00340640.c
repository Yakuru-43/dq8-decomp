// range: 0x340640 0x340650
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00340640(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13);
}
