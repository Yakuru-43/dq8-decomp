// range: 0x3022C0 0x302310
#include "common.h"

s32 func_003022C0(s32 *arg0, s32 arg1) {
    s32 mgr;
    s32 arr;
    s32 slots;

    mgr = arg0[0];
    if (mgr == 0) {
        return 0;
    }
    arr = arg0[1];
    if (arr == 0) {
        return 0;
    }
    slots = ((s32 *)mgr)[12];
    if (slots >= 0 && arg1 < slots) {
        return arr + arg1 * 64;
    }
    return 0;
}
