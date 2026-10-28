// range: 0x1EC0B0 0x1EC0F0
#include "common.h"

s32 func_001EC0B0(s32 *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < *arg0)) {
        return arg0[arg1 + 1];
    }
    return 0;
}
