// range: 0x166D60 0x166D80
#include "common.h"

s32 func_00166D60(s32 arg0, s32 arg1) {
    if (arg1 == 10003) {
        return 1;
    }
    return (u32)(arg1 ^ 10) < 1;
}
