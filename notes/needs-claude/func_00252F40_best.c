// best attempt for func_00252F40 (score=17, 17 words differ, 204 vs 204)
// range: 0x252F40 0x253010
#include "common.h"

extern s32 D_003E0BD0;
extern u16 D_003E0BD4;

typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ s8 pad_04[0x10];
} PoolItem;

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 tag;
    /* 0x04 */ s16 count;
    /* 0x06 */ s8 pad_06[0x06];
    /* 0x0C */ PoolItem *items;
} PoolEntry;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s16 count;
    /* 0x12 */ s8 pad_12[0x02];
    /* 0x14 */ PoolEntry *entries;
} PoolGroup;

PoolItem *func_00252F40(s32 key) {
    s32 max;
    s32 i;
    s32 j;
    s32 k;
    s32 groupCount;
    s32 entryCount;
    PoolGroup *group;
    PoolEntry *entry;
    PoolItem *item;

    max = D_003E0BD4;
    for (i = 0; (i >= 0) && (i < max); i++) {
        group = (PoolGroup *)(D_003E0BD0 + (i << 5));
        if (group == 0) {
            return 0;
        }
        groupCount = group->count;
        if (groupCount > 0) {
            for (j = 0; j < groupCount; j++) {
                entry = &group->entries[j];
                if (entry->tag == 0x7F) {
                    entryCount = entry->count;
                    for (k = 0; k < entryCount; k++) {
                        item = &entry->items[k];
                        if (item->id == key) {
                            return item;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
