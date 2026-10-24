// range: 0x211430 0x211480
#include "common.h"

typedef struct {
    s32 key;
    char pad4[0xC];
} Entry;

typedef struct {
    s32 count;
    char pad4[0xC];
    Entry entries[1]; /* +0x10 */
} Table;

extern Table *D_003E08DC;

Entry *func_00211430(s32 key) {
    Table *table;
    Entry *entry;
    s32 i;

    table = D_003E08DC;
    if (table == 0) {
        return 0;
    }
    entry = table->entries;
    for (i = 0; i < table->count; i++, entry++) {
        if (key == entry->key) {
            return entry;
        }
    }
    return 0;
}
