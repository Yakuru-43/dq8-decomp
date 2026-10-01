// range: 0x170500 0x170510
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00170500(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x214);
}
