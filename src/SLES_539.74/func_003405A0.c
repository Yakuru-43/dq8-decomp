// range: 0x3405A0 0x3405B0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_003405A0(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x24) & arg1) != 0;
}
