// range: 0x301350 0x3014F0
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

struct Record {
    s32 values[16];
};

struct RecordSet {
    char pad0[4];
    Record *records; /* +0x04 */
    char pad8[0x14];
    s32 index; /* +0x1C */
};

struct Entry {
    s32 key;
    s32 count;
};

struct EntryList {
    s32 n;
    Entry entries[1];
};

extern "C" {

extern s32 func_002B0A30(void *table, s32 key);
extern char D_0042EA80[];

/* Sums weight * count over the list, then takes single items back off
 * (count >= 2 only) while the sum exceeds the threshold for this mode. */
bool func_00301350(RecordSet *set, EntryList *list) {
    Record record;
    f32 sum;
    s32 n;
    s32 mode;
    bool found;
    bool changed;
    s32 count;
    s32 weight;
    s32 i;

    changed = false;
    sum = 0.0f;
    for (i = 0; i < list->n; i++) {
        count = list->entries[i].count;
        weight = func_002B0A30(D_0042EA80, list->entries[i].key);
        sum += (f32)weight * (f32)count;
    }

    record = set->records[set->index];
    mode = record.values[3] / 100;

    for (;;) {
        f32 threshold = 180.0f;
        if (mode == 35) {
            threshold = 160.0f;
        }
        if (sum <= threshold) {
            break;
        }
        n = list->n;
        found = false;
        for (i = 0; i < n; i++) {
            if (list->entries[i].count >= 2) {
                sum -= (f32)func_002B0A30(D_0042EA80, list->entries[i].key);
                changed = found = true;
                list->entries[i].count--;
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    return changed;
}

}
