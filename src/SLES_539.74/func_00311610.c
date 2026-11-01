// range: 0x311610 0x311780
#include "common.h"

s32 func_00181420(void);
s32 func_00201DB0(s32);
s32 func_002067E0(s32, s32, s32);

struct Entry {
    s8 text[6];
};
extern struct Entry D_003AD7F0[];

s32 func_00311610(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 ret;
    s32 handle;
    s32 idx;
    s32 r;
    s32 n;
    s8 *p;
    s8 c;
    s32 i;

    ret = -1;
    handle = func_00181420();
    idx = ret;
    if (arg2 == 0) {
        r = func_00201DB0(handle);
        n = func_002067E0(r, arg0, arg1);
        if (0 < n) {
            ret = 0x7E;
            idx = 0;
        } else {
            ret = 0x77;
            idx = 1;
        }
    }
    if (arg2 == 1) {
        r = func_00201DB0(handle);
        n = func_002067E0(r, arg0, arg1);
        if (0 < n) {
            ret = 0x7D;
            idx = 3;
        } else {
            ret = 0x6A;
            idx = 2;
        }
    }
    if (arg0 == 4) {
        ret = 0x76;
        idx = 5;
    }
    if (arg3 != 0) {
        if (0 <= idx) {
            p = D_003AD7F0[idx].text;
            i = 0;
            while (!((c = p[i]) <= -1)) {
                arg3[i] = c;
                i++;
            }
            arg3[i] = -1;
        }
    }
    return ret;
}
