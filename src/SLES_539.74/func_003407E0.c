// range: 0x3407E0 0x3407F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003407E0(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x13) == 4;
}
