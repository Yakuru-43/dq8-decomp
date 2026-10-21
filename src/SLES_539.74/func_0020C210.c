// range: 0x20C210 0x20C240
#include "common.h"

s32 func_0020C210(char *arg0) {
    s32 idx;
    char *p;

    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        p = 0;
    } else {
        p = arg0 + idx * 0xC0 + 0x5610;
    }
    return M2C_FIELD(p, s32 *, 0x14);
}
