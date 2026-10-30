// range: 0x3134A0 0x313520
#include "common.h"

extern s32 func_0024C7C0(void *, s32);

s32 func_003134A0(s32 arg0, s32 arg1, void *arg2) {
    switch (arg0) {
    default:
        break;
    case 0:
        if (func_0024C7C0(arg2, 1) != 0) {
            return 1;
        }
        break;
    case 1:
        if (func_0024C7C0(arg2, 1) != 0) {
            if (arg1 != 0) {
                return 1;
            }
        }
        break;
    }
    return 0;
}
