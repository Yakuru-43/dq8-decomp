// range: 0x102B90 0x102C10
#include "common.h"

struct Counted {
    s32 count;
};

struct Entry {
    void *block;
    struct Counted *counted;
};

extern void func_00100780(void *block);
extern void func_001007A0(void *node);

void *func_00102B90(struct Entry *entry, s16 n) {
    struct Counted *counted;
    s32 count;

    if (entry != 0) {
        counted = entry->counted;
        if (counted != 0) {
            count = counted->count - 1;
            counted->count = count;
            if (count == 0) {
                func_00100780(entry->block);
                func_001007A0(entry->counted);
            }
        }
        if (n > 0) {
            func_001007A0(entry);
        }
    }
    return entry;
}
