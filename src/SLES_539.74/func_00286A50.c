// range: 0x286A50 0x286A90
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

void func_001FC510();  /* extern */

void func_00286A50(ListOwner *owner) {
    ListEntry *entry = owner->list;

    while (entry != 0) {
        if (entry->obj != 0) {
            func_001FC510(entry->obj);
        }
        entry = entry->next;
    }
}
