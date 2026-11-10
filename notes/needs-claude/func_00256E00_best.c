// range: 0x256E00 0x256EC0
// best attempt, score 20 reorder+register (188 vs 188 bytes) — NOT a match,
// do not stage. See notes/needs-claude/func_00256E00.md
#include "common.h"

typedef struct {
    /* 0x00 */ s8 bit;
    /* 0x01 */ u8 pad1[3];
    /* 0x04 */ s16 count;
    /* 0x06 */ u8 pad6[6];
    /* 0x0C */ s32 *items;
} SelEntry;

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s16 count;
    /* 0x14 */ SelEntry *entries;
    /* 0x18 */ u8 pad18[8];
} SelGroup;

typedef struct {
    /* 0x00 */ s32 key;
    /* 0x04 */ s32 mask;
} SelObj;

extern SelGroup *D_003E0BD0;
extern u16 D_003E0BD4;

s32 func_00256E00(SelObj *obj) {
    SelGroup *group;
    SelEntry *entry;
    s32 i;
    s32 j;
    s32 k;

    if (obj == 0) {
        return -1;
    }
    obj->mask = 0;
    i = 0;
    group = D_003E0BD0;
    for (; i < (s32)D_003E0BD4; i++, group++) {
        if (group->count > 0) {
            entry = group->entries;
            for (j = 0; j < group->count; j++, entry++) {
                for (k = 0; k < entry->count; k++) {
                    if (obj->key == entry->items[k * 5]) {
                        obj->mask |= 1 << entry->bit;
                        break;
                    }
                }
            }
        }
    }
    return -1;
}
