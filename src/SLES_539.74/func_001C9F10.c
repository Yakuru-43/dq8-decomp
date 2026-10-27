// range: 0x1C9F10 0x1C9FF0
#include "common.h"

s32 func_001A2130(s32);
s32 func_001A2190(s32);

s32 func_001C9F10(char *arg0, s32 arg1) {
    s32 val;
    s32 a1;
    s32 v1;
    s32 ret;

    if (*(s32 *)(arg0 + 0) == 1) {
        val = (s32)*(f32 *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }

    ret = func_001A2190(val);
    if (ret == 0) {
        return 0;
    }

    switch (arg1) {
    case 5:
        return 1;
    case 3:
        v1 = *(s32 *)(arg0 + 8);
        if (v1 == 1) {
            a1 = (s32)*(f32 *)(arg0 + 0xC);
        } else {
            a1 = *(s32 *)(arg0 + 0xC);
        }
        if (func_001A2130(a1) == 0) {
            return 0;
        }
        v1 = *(s32 *)(arg0 + 0x10);
        if (v1 == 1) {
            a1 = (s32)*(f32 *)(arg0 + 0x14);
        } else {
            a1 = *(s32 *)(arg0 + 0x14);
        }
        if (func_001A2130(a1) != 0) {
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
