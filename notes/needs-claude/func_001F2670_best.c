// range: 0x1F2670 0x1F2760
#include "common.h"

s32 func_001F2670(s32 *arg0, s32 arg1, f32 *arg2) {
    s32 arr;
    s32 n;
    s32 mark;
    s32 count;
    f32 lo;
    f32 hi;
    f32 v;

    arg0[2] = 0;
    arr = arg0[1];
    if (arr != 0 && arg1 >= 0 && arg1 < 11) {
        arg0[2] = *(s32 *)(arr + arg1 * 4);
    }
    count = 0;
    for (;;) {
        n = arg0[2];
        if (n != 0) {
            arg0[2] = *(s32 *)n;
            n = *(s32 *)(n + 0x10);
        }
        if (n == 0) {
            arg0[2] = 0;
            return count;
        }
        if (*(s32 *)(n + 0x44) == 0) {
            mark = 0;
        } else if (arg2 == 0) {
            mark = 1;
        } else {
            lo = *(f32 *)(n + 0x58);
            hi = *(f32 *)(n + 0x5C);
            v = *arg2;
            if (lo < hi) {
                mark = (lo <= v) && (v < hi);
            } else {
                mark = (lo <= hi) || (v >= lo) || (v < hi);
            }
        }
        *(s32 *)(n + 0x48) = mark;
        if (mark != 0) {
            count++;
        }
    }
}
