// range: 0x3838A0 0x3838B0
// auto: m2c, verified byte-exact
#include "common.h"

s8 func_003838A0(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg1 + arg0), s8 *, 0x44);
}
