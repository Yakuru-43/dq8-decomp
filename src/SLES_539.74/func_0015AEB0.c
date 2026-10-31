// range: 0x15AEB0 0x15AEF0
#include "common.h"

s32 func_0015AEB0(char *arg0, s32 arg1) {
    if (arg1 == 0x7FFF) {
        return (s32)(arg0 + 0x20);
    }
    if (arg1 >= 0) {
        if (arg1 < *(s32 *)(arg0 + 0xC)) {
            return *(s32 *)(arg0 + 0x1C) + (arg1 << 4);
        }
    }
    return 0;
}
