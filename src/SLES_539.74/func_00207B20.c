// range: 0x207B20 0x207B40
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00207B20(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s64 *, 0x28) & (1 << arg1)) != 0;
}
