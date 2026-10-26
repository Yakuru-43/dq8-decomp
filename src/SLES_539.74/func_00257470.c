// range: 0x257470 0x2574B0
#include "common.h"

s32 func_00257470(s32 *arg0, s32 arg1) {
    if (arg1 >= 0) {
        if (arg1 < *(s16 *)(arg0 + 1)) {
            return *(s16 *)(*arg0 + arg1 * 12);
        }
    }
    return 0;
}
