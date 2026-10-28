// range: 0x1C9960 0x1C99E0
#include "common.h"

s32 func_001A2190(s32);
s32 func_002F6340(void *, s32);

s32 func_001C9960(char *arg0) {
    s32 val;
    s32 a1;
    void *ret;

    if (*(s32 *)(arg0 + 0) == 1) {
        val = (s32)*(f32 *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }

    ret = (void *)func_001A2190(val);
    if (ret == 0) {
        return 0;
    }

    if (*(s32 *)(arg0 + 8) == 1) {
        a1 = (s32)*(f32 *)(arg0 + 0xC);
    } else {
        a1 = *(s32 *)(arg0 + 0xC);
    }

    func_002F6340(ret, a1);
    return 1;
}
