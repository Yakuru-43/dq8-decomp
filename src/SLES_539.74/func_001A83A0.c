// range: 0x1A83A0 0x1A83F0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001A83A0(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 8) == 0) && (M2C_FIELD(arg0, s32 *, 0x10) == 0) && (M2C_FIELD(arg0, s32 *, 0x18) == 0) && (M2C_FIELD(arg0, s32 *, 0x20) == 0)) {
        return 1;
    }
    return 0;
}
