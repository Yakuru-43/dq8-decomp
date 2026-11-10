// range: 0x258FA0 0x2590C0
#include "common.h"

typedef struct LruEntry {
    /* 0x00 */ u8 used;
    /* 0x01 */ u8 pad01[0xF];
    /* 0x10 */ s32 key;
    /* 0x14 */ s32 count;
} LruEntry;

extern LruEntry *D_003E0BC4;
extern void *func_00130FD0(void *dst, const void *src, u32 n);

void func_00258FA0(s32 arg0) {
    LruEntry *e;
    LruEntry *q;
    s32 found;
    s32 i;
    s32 free;
    s32 k;
    LruEntry *slot;

    if (D_003E0BC4 == 0 || arg0 <= 0) {
        found = 1;
    } else {
        e = D_003E0BC4;
        for (i = 0; i < 24; i++, e++) {
            if (e->key == arg0) {
                found = 1;
                goto found_check;
            }
        }
        found = 0;
    }
found_check:
    if (found == 1) {
        return;
    }
    free = -1;
    q = D_003E0BC4;
    for (i = 0; i < 24; i++) {
        if (q->key == 0) {
            free = i;
        }
        q++;
    }
    if (free < 0) {
        for (k = 0; k < 23; k++) {
            func_00130FD0((char *)D_003E0BC4 + k * 0x18,
                          (char *)D_003E0BC4 + (k + 1) * 0x18, 0x18);
        }
        free = 23;
    }
    slot = (LruEntry *)(free * 0x18 + (char *)D_003E0BC4);
    slot->key = arg0;
}
