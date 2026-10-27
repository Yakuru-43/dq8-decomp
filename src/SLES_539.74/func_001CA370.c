// range: 0x1CA370 0x1CA3C0
#include "common.h"

s32 func_001A2130(s32);

s32 func_001CA370(float *arg0) {
    s32 a;
    if (*(s32 *)arg0 == 1) {
        a = (s32)arg0[1];
    } else {
        a = ((s32 *)arg0)[1];
    }
    if (func_001A2130(a) != 0) {
        return 1;
    }
    return 0;
}
