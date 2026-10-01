// range: 0x340540 0x340550
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340540(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x28) & arg1) != 0;
}
