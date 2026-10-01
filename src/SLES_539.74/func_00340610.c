// range: 0x340610 0x340620
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340610(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, u8 *, 0x18) & arg1) != 0;
}
