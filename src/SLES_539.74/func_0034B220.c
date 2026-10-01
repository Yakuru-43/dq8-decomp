// range: 0x34B220 0x34B230
// auto: m2c, verified byte-exact
#include "common.h"

extern void *D_003E0B34;

s32 func_0034B220(void) {
    return M2C_FIELD(D_003E0B34, s32 *, 0x20);
}
