// range: 0x301280 0x3012B0
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00301280(void *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, u8 *, 0xC) != 0) && (arg1 & 1)) {
        return *M2C_FIELD(arg0, u8 **, 0x10);
    }
    return 0U;
}
