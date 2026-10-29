// range: 0x27E7F0 0x27E890
#include "common.h"

f32 func_0027E090(void *, s32);
s32 func_0027E700(s32, s32, s32, s32, void *);

s32 func_0027E7F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf[16];
    s32 ret;

    if (arg0 != 0 && arg1 > 0) {
        if (func_0027E090(buf, arg3) == 0.0f) {
            ret = 0;
        } else {
            ret = func_0027E700(arg0, arg1, arg2, arg3, buf);
        }
        return ret;
    }
    return 0;
}
