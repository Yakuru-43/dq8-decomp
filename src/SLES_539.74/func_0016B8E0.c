// range: 0x16B8E0 0x16B920
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0016B8E0(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0x3A44))) {
        return arg0 + (arg1 * 0x3C) + 0x3A48;
    }
    return NULL;
}
