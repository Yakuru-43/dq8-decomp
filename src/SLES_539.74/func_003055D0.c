// range: 0x3055D0 0x305660
#include "common.h"

s32 func_00167A80();                                /* extern */
s32 func_00371970(s32, s32);                        /* extern */
extern s32 D_003E114C;

s32 func_003055D0(s32 arg0) {
    s32 count;
    s32 ret;
    s32 one = 1;

    count = arg0;
    if (arg0 < 0) {
        count = 10;
    }
    ret = func_00371970(func_00167A80(), 2);
    if ((ret == one) || (ret == -1) || (ret == 3)) {
        return one;
    }
    if (D_003E114C < count) {
        D_003E114C = D_003E114C + 1;
        return one;
    }
    return 0;
}
