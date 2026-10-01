// range: 0x333B00 0x333B10
// auto: m2c, verified byte-exact
#include "common.h"

s16 func_00333B00(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0xC);
}
