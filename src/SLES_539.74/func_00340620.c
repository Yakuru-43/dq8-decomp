// range: 0x340620 0x340630
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00340620(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x17);
}
