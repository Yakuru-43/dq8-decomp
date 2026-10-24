// range: 0x308740 0x308760
// auto: hand, verified byte-exact
#include "common.h"

struct EntryTable {
    u16 entries[0x20];
    s8 index;
};

u16 func_00308740(struct EntryTable *table) {
    return table->entries[table->index];
}
