// range: 0x1EC170 0x1EC1B0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_001EC170(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0xA4))) {
        return arg0 + (arg1 * 8) + 0xA8;
    }
    return NULL;
}
