// range: 0x20B300 0x20B350
#include "common.h"

s32 func_0020B300(char *arg0, s32 arg1) {
    s32 idx;
    char *p;

    idx = *(s32 *)(arg0 + 0x5874);
    if (arg1 < 0) {
        return 0;
    }
    if (idx < 0) {
        p = 0;
    } else {
        p = arg0 + idx * 0xC0 + 0x5610;
    }
    return arg1 != *(s32 *)(p + 8);
}
