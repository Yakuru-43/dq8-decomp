// range: 0x257380 0x2573C0
#include "common.h"

struct Entry {
    s16 f0;
    s16 f2;
    s32 f4;
};

/* clears count entries of the table *arg0, starting at index from */
void func_00257380(s32 *arg0, s32 from, s32 count) {
    struct Entry *entry;
    s32 end = from + count;
    s32 i = from;

    while (i < end) {
        s32 off = i * 12;

        i = i + 1;
        entry = (struct Entry *)(*arg0 + off);
        entry->f0 = 0;
        entry->f2 = -1;
        entry->f4 = 0;
    }
}
