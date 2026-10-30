// best attempt (148 B, score 40) — range line removed, inert
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

extern s32 func_001FC820(void *obj, s32 key);
extern s32 func_001FC4E0(void *obj, s32 result);

s32 func_00286BE0(ListOwner *owner, s32 key)
{
    ListEntry *entry;
    void *obj;
    s32 result;

    entry = owner->list;
    obj = 0;
    result = 0;
    while (entry != 0) {
        obj = entry->obj;
        if (obj == 0) {
            entry = entry->next;
            continue;
        }
        result = func_001FC820(obj, key);
        if (result < 0) {
            obj = 0;
            entry = entry->next;
            continue;
        }
        break;
    }
    if (obj != 0) {
        result = func_001FC4E0(obj, result);
    }
    return result;
}
