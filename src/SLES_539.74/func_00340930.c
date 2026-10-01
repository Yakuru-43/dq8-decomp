// range: 0x340930 0x340940
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340930(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC) == 0;
}
