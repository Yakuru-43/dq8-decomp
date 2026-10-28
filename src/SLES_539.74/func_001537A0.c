// range: 0x1537A0 0x1537E0
#include "common.h"

s32 func_001537A0(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < *(s32 *)(arg0 + 0))) {
        return *(s32 *)(*(s32 *)(arg0 + 4) + (arg1 * 4));
    }
    return 0;
}
