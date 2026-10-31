// range: 0x3408D0 0x340900
#include "common.h"

s32 func_003408D0(char *arg0) {
    if (*(s32 *)(arg0 + 0x3C) == 0) {
        return 0;
    }
    return *(s32 *)(arg0 + 0x40) == 0;
}
