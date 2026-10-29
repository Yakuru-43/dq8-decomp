// range: 0x243010 0x2430C0
#include "common.h"

s32 func_00243010(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 base;
    s32 stride;
    s32 *ptr;

    if (arg2 == 0) {
        return -1;
    }

    if (arg1 < 4) {
        i = 0;
        stride = arg1 * 0xF0;
        while (i < 0xC) {
            ptr = (s32 *)(arg0 + stride + i * 0x14);
            if (arg2 == ptr[0x31] && ptr[0x34] > 0) {
                return i;
            }
            i++;
        }
    } else {
        i = 0;
        while (i < 0x18C) {
            ptr = (s32 *)(arg0 + i * 0x14);
            if (arg2 == ptr[0x121]) {
                return i;
            }
            i++;
        }
    }

    return -1;
}
