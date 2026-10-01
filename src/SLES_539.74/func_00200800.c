// range: 0x200800 0x200810
// auto: m2c, verified byte-exact
#include "common.h"

s8 func_00200800(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0x46);
}
