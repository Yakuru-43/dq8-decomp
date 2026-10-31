// range: 0x29DDD0 0x29DE30
#include "common.h"

typedef struct {
    s32 key;
    char body[0x3C];
} S_entry;

extern void func_00131080(void *dst, void *src, s32 len);

void func_0029DDD0(S_entry *entries, s32 index, s32 value) {
    S_entry *entry;
    s32 held;

    held = value;
    if (index >= 0 && index < 4) {
        entry = &entries[index];
        func_00131080(entry->body, entry, 0x3C);
        entry->key = held;
    }
}
