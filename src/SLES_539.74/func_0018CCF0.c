// range: 0x18CCF0 0x18CD50
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0018CCF0(char *arg0, s32 arg1) {
    if (arg1 == -1) {
        return arg0 + (M2C_FIELD(arg0, s32 *, 0x53AC) * 0x18) + 0x53B0;
    }
    if ((arg1 >= 0) && (arg1 < 2)) {
        return arg0 + (arg1 * 0x18) + 0x53B0;
    }
    return arg0 + 0x53B0;
}
