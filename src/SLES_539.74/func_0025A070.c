// range: 0x25A070 0x25A0B0
#include "common.h"

extern char *D_003E0C48;

char *func_0025A070(s32 arg0) {
    char *base;

    base = D_003E0C48;
    if (base == 0) {
        return 0;
    }
    if (arg0 >= 0) {
        if (arg0 < *(s32 *)base) {
            return base + (arg0 << 5) + 0x30;
        }
    }
    return 0;
}
