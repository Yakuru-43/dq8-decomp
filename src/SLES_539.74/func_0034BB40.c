// range: 0x34BB40 0x34BB50
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0034BB40(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8) - M2C_FIELD(arg0, s32 *, 0xC);
}
