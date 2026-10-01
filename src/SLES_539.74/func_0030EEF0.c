// range: 0x30EEF0 0x30EF10
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0030EEF0(char *arg0, s32 arg1) {
    return arg0 + M2C_FIELD(arg0, s32 *, 0x20) + (arg1 * 8);
}
