// range: 0x2914D0 0x291520
#include "common.h"

struct Owner {
    char pad[0x58C];
    u32 table;
};

struct Entry {
    char pad[0x10];
    s32 state;
    s32 sub;
};

extern s32 func_00292C60(struct Owner *owner);

/* arm or disarm the entry of the selected group's table */
void func_002914D0(struct Owner *owner) {
    struct Entry *entry = (struct Entry *)(owner->table + 0xE0);
    s32 running;

    running = func_00292C60(owner);
    if (running == 0) {
        entry->state = 0;
        entry->sub = 0;
    } else {
        entry->state = 2;
        entry->sub = 0;
    }
}
