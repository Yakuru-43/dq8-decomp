// range: 0x387E10 0x387F70
#include "common.h"

extern "C" {

struct Slot {
    /* 0x0 */ s16 count;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s32 unk4;
};

s32 func_00387E10(s32 arg0, s32 *slot, s32 idx, s32 count, Slot *base, bool dir) {
    s32 cur = *slot;
    s32 parity = cur % 2;
    s32 limit = parity + 4;
    s32 i;
    Slot *arr;

    if (dir) {
        dir = true;
        arr = base + idx * count;
        for (i = cur; i >= parity && dir; i -= 2) {
            if (arr[i].count > 0) {
                *slot = i;
                dir = false;
            }
        }
        if (dir) {
            while (*slot < limit && dir) {
                if (arr[limit].count > 0) {
                    *slot = limit;
                    dir = false;
                }
                limit -= 2;
            }
        }
        return -dir;
    } else {
        dir = true;
        arr = base + idx * count;
        for (i = cur; i <= limit && dir; i += 2) {
            if (arr[i].count > 0) {
                *slot = i;
                dir = false;
            }
        }
        if (dir) {
            while (parity < *slot && dir) {
                if (arr[parity].count > 0) {
                    *slot = parity;
                    dir = false;
                }
                parity += 2;
            }
        }
        return -dir;
    }
}

}
