// range: 0x301160 0x301170
// auto: m2c, verified byte-exact
#include "common.h"

u16 func_00301160(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u16 *, 2);
}
