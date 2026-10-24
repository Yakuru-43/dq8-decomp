// range: 0x30A840 0x30A880
#include "common.h"

s32 func_0030A840(s32 arg0[4][16], s32 arg1, s32 arg2) {
    if (arg1 < 0 || 4 <= arg1) {
        return -1;
    }
    return arg0[arg1][arg2];
}
