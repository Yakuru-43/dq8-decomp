// range: 0x3101F0 0x310390
#include "common.h"

struct Actor {
    char pad0[0x10];
    s16 inParty;
    char pad12[0x352];
    struct Inv *inv;
};

struct Inv {
    char pad0[0x62];
    u16 ids[6];
};

struct List {
    s32 count;
    s32 ids[1];
};

struct Desc {
    char pad0[0x20];
    s32 mask;
    s32 flags;
};

extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));
extern M2C_UNK D_003D0870 __attribute__((section(".data")));

extern s32 func_001FFBA0(void *arg0, s32 arg1);
extern void func_00300CB0(s32 arg0, M2C_UNK *arg1, s32 arg2);
extern s32 func_0030FD70(void *arg0, struct Desc *arg1);

s32 func_003101F0(struct Actor *actor, s32 key, struct List *list, s32 check) {
    struct Desc *desc;
    s32 i;

    if (actor->inParty == 0) {
        if (list == 0) {
            func_00300CB0(0, &D_003D0870, 0xF0);
            return 0;
        }
        for (i = 0; i < list->count; i++) {
            s32 id = list->ids[i];
            if (id <= 0) {
                continue;
            }
            if (id >= 0x2BA) {
                continue;
            }
            desc = (struct Desc *) func_001FFBA0(&D_0042CDB0, id);
            if (desc == 0) {
                continue;
            }
            if ((desc->mask & key) == 0) {
                continue;
            }
            if ((check != 0) && ((desc->flags & 1) == 0)) {
                continue;
            }
            if (func_0030FD70(actor, desc) == 0) {
                continue;
            }
            return 1;
        }
    } else {
        struct Inv *inv = actor->inv;
        if (inv == 0) {
            return 0;
        }
        for (i = 0; i < 6; i++) {
            u16 id = inv->ids[i];
            if (id <= 0) {
                continue;
            }
            if (id >= 0x2BA) {
                continue;
            }
            desc = (struct Desc *) func_001FFBA0(&D_0042CDB0, id);
            if (desc == 0) {
                continue;
            }
            if ((desc->mask & key) == 0) {
                continue;
            }
            if (func_0030FD70(actor, desc) == 0) {
                continue;
            }
            return 1;
        }
    }
    return 0;
}
