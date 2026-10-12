// range: 0x1E2520 0x1E2550
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001E2520(char *arg0, char *arg1) {
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        M2C_FIELD(arg1, s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x10);
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
        return 1;
    }
    return 0;
}
