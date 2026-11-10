// range: 0x1714D0 0x171590
#include "common.h"

extern void func_00172A20(s32, s32, s32, s32, s32);

struct KeyNote {
    u8 cleared;
    s8 key;
    s8 vel;
    s8 chan;
    u8 rest[8];
};

struct KeyList {
    s32 data0;
    s32 data4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    u8 pad18[0x14];
    s32 count;
    u8 pad30[8];
    struct KeyNote notes[1];
};

static inline s32 InRange(s32 i, s32 n) {
    s32 ok;

    if (i < 0) {
        ok = 0;
    } else if (i < n) {
        ok = 1;
    } else {
        ok = 0;
    }
    return ok;
}

void func_001714D0(struct KeyList *list) {
    s32 i;
    struct KeyNote *note;

    for (i = 0; i < list->count; i++) {
        if (InRange(i, list->count) != 0) {
            note = &list->notes[i];
            func_00172A20(list->data0, list->data4, note->key, note->vel,
                          note->chan);
            note->cleared = 0;
        }
    }
    list->f14 = 0;
    list->f10 = 0;
    list->f8 = 0;
    list->fC = 0;
}
