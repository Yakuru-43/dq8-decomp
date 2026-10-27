// range: 0x153630 0x153650
#include "common.h"

s32 func_00153630(s32 arg0, s32 arg1) {
    if (arg1 == 9) {
        return 1;
    }
    return (u32)(arg1 ^ 7) < 1;
}
