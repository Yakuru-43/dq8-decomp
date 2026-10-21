// range: 0x292CB0 0x292CC0
#include "common.h"

struct Owner {
    char pad[0x58C];
    s32 selected;
};

extern void func_00292A90(struct Owner *owner);

/* remember the selected group, then reset the counters */
void func_00292CB0(struct Owner *owner, s32 selected) {
    owner->selected = selected;
    func_00292A90(owner);
}
