// range: 0x358070 0x358080
// auto: m2c, verified byte-exact
#include "common.h"

s16 func_00358070(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x18);
}
