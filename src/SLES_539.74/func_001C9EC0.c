// range: 0x1C9EC0 0x1C9F10
#include "common.h"

s32 func_001A2190(s32);

s32 func_001C9EC0(float *arg0) {
    s32 a;
    if (*(s32 *)arg0 == 1) {
        a = (s32)arg0[1];
    } else {
        a = ((s32 *)arg0)[1];
    }
    if (func_001A2190(a) != 0) {
        return 1;
    }
    return 0;
}
