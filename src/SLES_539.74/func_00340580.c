// range: 0x340580 0x340590
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340580(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, u8 *, 0x16) & arg1) != 0;
}
