// range: 0x22A840 0x22A880
#include "common.h"

s32 func_0022A840(s32 arg0, s32 arg1) {
    s32 result;
    s32 i;

    if (arg1 <= 0) {
        return 1;
    }
    arg1 = arg1 - 1;
    result = arg0;
    i = 0;
    while (i < arg1) {
        result = result * arg0;
        i = i + 1;
    }
    return result;
}
