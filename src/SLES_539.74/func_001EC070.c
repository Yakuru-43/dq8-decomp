// range: 0x1EC070 0x1EC0B0
#include "common.h"

s32 func_001EC070(s32 *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < arg0[0x11])) {
        return arg0[arg1 + 0x12];
    }
    return 0;
}
