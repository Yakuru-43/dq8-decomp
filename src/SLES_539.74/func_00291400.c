// range: 0x291400 0x2914D0
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: cf. func_00301200.c)
#include "common.h"

struct Owner {
    char pad[0x58C];
    u32 table;
    s32 counters[6];
};

struct Entry {
    char pad[0x10];
    s32 state;
    s32 sub;
};

M2C_UNK func_00300CB0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern s32 func_00291520(struct Owner *owner, s32 kind);
extern s32 func_00292C60(struct Owner *owner);
extern s32 func_00132D38(void);
extern M2C_UNK D_003CB108 __attribute__((section(".data")));

/* pick the entry of the table past the (rem)-th still-running counter */
void func_00291400(struct Owner *owner) {
    struct Entry *entry = (struct Entry *)(owner->table + 0xE0);
    s32 idx;
    s32 count;
    s32 rem;
    s32 cnt;

    if (func_00292C60(owner) == 0) {
        idx = 0;
    } else {
        idx = 2;
    }
    count = func_00291520(owner, 0);
    func_00300CB0(0 < count, &D_003CB108, 0x1B97);
    rem = func_00132D38() % count + 1;
    while (rem != 0) {
        cnt = owner->counters[idx];
        idx = idx + 1;
        if (cnt > 0) {
            rem = rem - 1;
        }
        if (idx >= 6) {
            break;
        }
    }
    entry->state = idx - 1;
    entry->sub = 0;
}
