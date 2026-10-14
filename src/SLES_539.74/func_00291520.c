// range: 0x291520 0x2915F0
#include "common.h"

struct Group {
    s32 counters[6];
};

struct Owner {
    char pad[0x590];
    struct Group groups[3];
};

extern s32 func_00292C60(struct Owner *owner);

/* how many counters of the selected group are still running */
s32 func_00291520(struct Owner *owner, s32 kind) {
    struct Group *group;
    s32 count = 0;

    if ((kind & 0xFF) == 2) {
        group = &owner->groups[2];
    } else if ((kind & 0xFF) == 1) {
        group = &owner->groups[1];
    } else {
        group = &owner->groups[0];
    }
    if (func_00292C60(owner) == 0) {
        if (group->counters[0] > 0) {
            count = count + 1;
        }
        if (group->counters[1] > 0) {
            count = count + 1;
        }
    } else {
        if (group->counters[2] > 0) {
            count = count + 1;
        }
        if (group->counters[3] > 0) {
            count = count + 1;
        }
        if (group->counters[4] > 0) {
            count = count + 1;
        }
        if (group->counters[5] > 0) {
            count = count + 1;
        }
    }
    return count;
}
