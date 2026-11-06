// range: 0x3882F0 0x3883C0
#include "common.h"

struct Slot {
    /* 0x0 */ s16 count;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s32 unk4;
};

s32 func_003882F0(s32 arg0, s32 idx, s32 p3, s32 p4, struct Slot *base) {
    s32 parity;
    s32 prod;
    s32 i;

    parity = idx % 2;
    prod = p3 * p4;
    if (base[idx + prod].count > 0) {
        return idx;
    }
    i = idx - 2;
    if (i < parity) {
        i = parity;
    }
    if (base[i + prod].count > 0) {
        return i;
    }
    i = idx - 4;
    if (i < parity) {
        i = parity;
    }
    if (base[i + prod].count > 0) {
        return i;
    }
    i = idx - 6;
    if (i < parity) {
        i = parity;
    }
    if (base[i + prod].count > 0) {
        return i;
    }
    return -1;
}
