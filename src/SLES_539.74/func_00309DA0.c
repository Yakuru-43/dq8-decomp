// range: 0x309DA0 0x309DF0
#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 key;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} SearchEntry;

typedef struct {
    /* 0x00 */ SearchEntry *entries;
    /* 0x04 */ s32 count;
} SearchTable;

s32 func_00309DA0(SearchTable *table, s32 key) {
    s32 result = -1;
    s32 i;

    for (i = 0; i < table->count; i++) {
        if (table->entries[i].key == key) {
            result = i;
            break;
        }
    }
    return result;
}
