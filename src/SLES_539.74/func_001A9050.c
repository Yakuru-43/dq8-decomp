// range: 0x1A9050 0x1A9060
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A9050(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x424) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    return 0;
}
