// range: 0x20B2A0 0x20B2C0
#include "common.h"

s32 func_0020B2A0(char *arg0, s32 arg1) {
    if (arg1 < 0) {
        return 0;
    }
    return *(s32 *)(arg0 + 0x5F9C) != arg1;
}
