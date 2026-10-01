// range: 0x333E00 0x333E10
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00333E00(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x24);
}
