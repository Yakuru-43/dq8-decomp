// range: 0x3040A0 0x304150
#include "common.h"

struct Entry {
    s16 id;
    s8 type;
    s8 kind;
};

extern struct Entry D_003AD010[];                                   /* extern */
s32 func_00304270(s32, s32);                                         /* extern */
void func_00304380(s32, s32, s32);                                   /* extern */

void func_003040A0(s32 id, s32 type, s32 base) {
    struct Entry *entry;
    s32 cur;
    s32 sum;

    if (id < 0) {
        return;
    }
    entry = D_003AD010;
    for (;;) {
        cur = entry->id;
        if (cur < 0) {
            break;
        }
        if ((id == cur) && (type == entry->type)) {
            sum = base + func_00304270(1, entry->kind);
            if (sum < 0) {
                sum = 0;
            }
            if (sum > 0x2710) {
                sum = 0x2710;
            }
            func_00304380(1, entry->kind, sum);
        }
        entry++;
    }
}
