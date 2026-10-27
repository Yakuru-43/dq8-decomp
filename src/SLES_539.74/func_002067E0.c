// range: 0x2067E0 0x206880
#include "common.h"

s32 func_002072F0(s32, s32);

s32 func_002067E0(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    if (func_002072F0(arg0, arg1) == 0) {
        return 0;
    }
    if (arg2 < 0 || arg2 >= 0xC) {
        return 0;
    }
    for (i = 0; i < 5; i++) {
        s16 val = *(s16 *)((char *)arg0 + arg1 * 10 + i * 2 + 0x840);
        if (val == arg2) {
            return 1;
        }
    }
    return 0;
}
