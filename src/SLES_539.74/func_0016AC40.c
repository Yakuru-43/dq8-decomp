// range: 0x16AC40 0x16AC80
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0016AC40(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0x40D8))) {
        return arg0 + (arg1 * 0x3C) + 0x40DC;
    }
    return NULL;
}
