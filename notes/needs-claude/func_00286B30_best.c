// range: 0x286B30 0x286BE0
// best attempt, CLASS structural score=35 (120 vs 164 bytes); NOT a match, do not put in src/ as is
#include "common.h"

typedef struct ListEntry {
    /* 0x00 */ struct ListEntry *next;
    /* 0x04 */ u8 pad[0x10];
    /* 0x14 */ void *obj;
} ListEntry;

typedef struct {
    /* 0x000 */ u8 pad[0x220];
    /* 0x220 */ ListEntry *list;
} ListOwner;

s32 func_001FC820(void *obj, s32 key);
s32 func_001FC4A0(void *obj, s32 result);

s32 func_00286B30(ListOwner *owner, s32 key)
{
    void *obj;
    ListEntry *entry;
    s32 result;

    for (entry = owner->list; entry != 0; entry = entry->next) {
        obj = entry->obj;
        if (obj == 0) {
            continue;
        }
        result = func_001FC820(obj, key);
        if (result < 0) {
            continue;
        }
        goto found;
    }
    obj = 0;
found:
    if (obj != 0) {
        result = func_001FC4A0(obj, result);
    }
    return result;
}
