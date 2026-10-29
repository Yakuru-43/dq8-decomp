// range: 0x22AB70 0x22ABB0
#include "common.h"

s32 func_0022AB70(s32 arg0) {
    if (arg0 % 64 != 0) {
        arg0 = (arg0 / 64 + 1) * 64;
    }
    return arg0;
}
