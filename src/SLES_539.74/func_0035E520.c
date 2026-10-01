// range: 0x35E520 0x35E570
// auto: m2c, verified byte-exact
#include "common.h"

s64 func_0035E520(void *arg0, s64 arg1, s32 arg2) {
    if (arg2 == 0) {
        M2C_FIELD(arg0, s64 *, 0x158) = arg1;
    }
    if (arg2 == 1) {
        M2C_FIELD(arg0, s64 *, 0x158) = (s64) (M2C_FIELD(arg0, s64 *, 0x158) | arg1);
    }
    if (arg2 == 2) {
        M2C_FIELD(arg0, s64 *, 0x158) = (s64) (M2C_FIELD(arg0, s64 *, 0x158) & ~arg1);
    }
    return M2C_FIELD(arg0, s64 *, 0x158);
}
