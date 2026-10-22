// best C for func_00302140 (NOT matched — div guard; kept out of src/)
// range: 0x302140 0x3022C0
#include "common.h"

s32 func_00302140(s32 *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    s32 mgr;
    s32 quotient;
    s32 baseIndex;
    s32 count;
    s32 limit;
    s32 i;
    s32 entry;
    s32 result;
    s32 arr;
    s32 slots;
    s32 mask;
    s32 j;

    mgr = arg0[0];
    if (mgr == 0) {
        return 0;
    }
    quotient = arg1 / 100;
    count = ((s32 *)mgr)[12];
    baseIndex = 0;
    if (arg3 != 0) {
        *arg3 = 0;
    }
    mgr = arg0[0];
    limit = ((s32 *)mgr)[18];
    for (i = 0; i < limit; i++) {
        entry = arg0[5];
        if (*(u16 *)(entry + i * 8) == quotient) {
            count = *(u16 *)(entry + i * 8 + 2);
            baseIndex = *(s32 *)(entry + i * 8 + 4);
            break;
        }
    }
    result = 0;
    if (arg0[0] != 0) {
        arr = arg0[1];
        if (arr != 0) {
            slots = ((s32 *)mgr)[12];
            if (slots >= 0 && baseIndex < slots) {
                result = arr + baseIndex * 64;
            }
        }
    }
    mask = 1 << arg2;
    for (j = 0; j < count; j++) {
        entry = result + j * 64;
        if (*(s32 *)(entry + 0xC) == arg1) {
            if (mask & *(u8 *)(entry + 6)) {
                if (arg3 != 0) {
                    *arg3 = baseIndex + j;
                }
                return result;
            }
        }
    }
    if (mgr != 0) {
        arr = arg0[1];
        if (arr != 0) {
            slots = ((s32 *)mgr)[12];
            if (slots >= 0 && slots > 0) {
                return arr;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
