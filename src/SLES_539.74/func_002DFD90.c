// range: 0x2DFD90 0x2DFDB0
#include "common.h"

/* half the queued count, rounding toward zero */
s32 func_002DFD90(char *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x9C) / 2;
}
