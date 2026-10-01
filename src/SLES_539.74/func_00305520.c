// range: 0x305520 0x305540
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00305520(void *arg0, s32 arg1) {
    return (M2C_FIELD(arg0, s32 *, 0x40) & (1 << arg1)) != 0;
}
