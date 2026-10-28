// range: 0x205FB0 0x206080
#include "common.h"

s32 func_00205D30(s32, s32);

void func_00205FB0(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;
    s32 val;

    if (arg2 == 0) {
        i = 0;
        do {
            val = func_00205D30(arg0, i);
            *(s32 *)((char *)arg1 + (i << 2)) = val;
            i++;
        } while (i < 4);
    } else if (arg2 == 1) {
        j = 0;
        i = 0;
        do {
            val = func_00205D30(arg0, i);
            if (val != 0) {
                *(s32 *)((char *)arg1 + (j << 2)) = val;
                j++;
            }
            i++;
        } while (i < 4);
    }
}
