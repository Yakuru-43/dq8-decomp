// range: 0x325DA0 0x325E40
#include "common.h"

extern M2C_UNK func_00320F40(f32, s32);
extern f32 func_003210C0(s32, s32);

s32 func_00325DA0(char *arg0) {
    s32 count;
    s32 idx;
    f32 min;
    f32 val;

    count = *(s32 *)arg0;
    min = 0.0f;

    if (count > 0) {
        min = func_003210C0(*(s32 *)(arg0 + 4), 0);
    }

    idx = 1;
    while (idx < count) {
        val = func_003210C0(*(s32 *)(arg0 + 4), idx);
        if (val < min) {
            min = val;
        }
        idx++;
    }

    func_00320F40(min, *(s32 *)(arg0 + 4));
    return 0;
}
