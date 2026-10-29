// range: 0x1FC420 0x1FC460
#include "common.h"

s32 func_001FC420(s32 *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < *arg0)) {
        return arg0[arg1 + 49];
    }
    return 0;
}
