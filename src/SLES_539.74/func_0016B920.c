// range: 0x16B920 0x16B960
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0016B920(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0x550))) {
        return arg0 + (arg1 << 6) + 0x554;
    }
    return NULL;
}
