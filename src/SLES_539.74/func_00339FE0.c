// range: 0x339FE0 0x33A090
#include "common.h"

s32 func_00339FE0(char *arg0) {
    s32 *base;
    s32 count;
    s32 i;
    s32 offset;
    s32 val;

    base = *(s32 **)(arg0 + 8);
    if (base == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        offset = i * 0x220;
        val = *(s32 *)((char *)base + offset + 0x184);
        if (val < 0) {
            *(s32 *)(arg0 + 4) = *(s32 *)(arg0 + 4) + 1;
            return *(s32 *)(arg0 + 8) + offset;
        }
    }
    count = *(s32 *)(arg0 + 0xC);
    for (i = 0; i < count; i++) {
        offset = i * 0x220;
        val = *(s32 *)((char *)(*(s32 *)(arg0 + 0x10)) + offset + 0x184);
        if (val < 0) {
            *(s32 *)(arg0 + 4) = *(s32 *)(arg0 + 4) + 1;
            return *(s32 *)(arg0 + 0x10) + offset;
        }
    }
    return 0;
}
