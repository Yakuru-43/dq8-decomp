// range: 0x18FCE0 0x18FD00
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0018FCE0(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x28) + (M2C_FIELD(arg0, s32 *, 0x2C) * 0x10);
}
