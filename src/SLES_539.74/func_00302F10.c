// range: 0x302F10 0x302F40
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00302F10(void *arg0) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s16 *, 0x44) == 2)) {
        return 1;
    }
    return 0;
}
