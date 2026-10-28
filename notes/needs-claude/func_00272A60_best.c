// best attempt for func_00272A60 (score 9, 104 vs 120 bytes) — see
// func_00272A60.md. No `// range:` line on purpose: gen_configs must not
// link this into the build.
#include "common.h"

typedef union Stamp {
    float f;
    u32 word;
    u16 half[2];
} Stamp;

typedef struct Entry {
    u32 field_00[4];
} Entry;

typedef struct EntryList {
    u32 field_00;
    u32 count;
    Entry *entries;
    u32 field_0C;
    u32 field_10;
    u32 *keys;
} EntryList;

Entry *func_00272A60(EntryList *list, Stamp stamp)
{
    Stamp key;
    u32 index;
    u32 elem;
    Entry *result;

    key = stamp;
    if (!(key.word != 0) != 0) {
        result = NULL;
    } else {
        index = key.half[0];
        if (index < list->count) {
            elem = list->keys[index];
            if (elem == key.half[1]) {
                result = list->entries + index;
            } else {
                result = NULL;
            }
        } else {
            result = NULL;
        }
    }
    return result;
}
