// range: 0x301190 0x3011C0
// auto: m2c, verified byte-exact
#include "common.h"

u8 func_00301190(void *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, u8 *, 0xC) != 0) && (arg1 & 2)) {
        return *M2C_FIELD(arg0, u8 **, 0x10);
    }
    return 0U;
}
