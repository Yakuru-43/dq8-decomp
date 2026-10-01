// range: 0x301250 0x301260
// auto: m2c, verified byte-exact
#include "common.h"

u16 func_00301250(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u16 *, 2);
}
