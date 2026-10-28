// range: 0x1FC460 0x1FC4A0
#include "common.h"

s32 func_001FC460(s32 *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < *arg0)) {
        return arg0[arg1 + 1];
    }
    return 0;
}
