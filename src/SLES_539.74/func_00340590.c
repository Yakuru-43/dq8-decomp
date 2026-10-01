// range: 0x340590 0x3405A0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00340590(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x24) & arg1) != 0;
}
