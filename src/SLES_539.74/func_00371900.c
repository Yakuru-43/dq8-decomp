// range: 0x371900 0x371970
#include "common.h"

s32 func_0025B910(s16, s32);

s32 func_00371900(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;
    char *v1;

    if (arg1 >= 0 && arg1 < 6) {
        v1 = *(char **)(arg0 + (arg1 * 4));
    } else {
        v1 = 0;
    }
    if (v1 == 0) {
        return 0;
    }
    if (*(u8 *)v1 == 0) {
        ret = 0;
    } else {
        ret = func_0025B910(*(s16 *)(v1 + 2), arg2);
    }
    return ret;
}
