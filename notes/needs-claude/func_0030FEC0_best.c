// Best attempt for func_0030FEC0 (see func_0030FEC0.md). NOT matched, NOT
// linked (kept out of src/ so `make -j` never picks it up).
// range: 0x30FEC0 0x310050
#include "common.h"

struct Inv {
    u8 pad0[0x62];
    u16 ids[6];
};

struct Actor {
    u8 pad0[0x10];
    s16 inParty;
    u8 pad12[0x352];
    struct Inv *inv;
};

struct Desc {
    u8 pad0[0x24];
    s32 flags;
};

extern M2C_UNK D_003D0870 __attribute__((section(".data")));
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

extern struct Desc *func_001FFBA0(void *table, s32 id);
extern void func_00300CB0(s32 arg0, M2C_UNK *arg1, s32 arg2);
extern s32 func_0030FD70(void *actor, struct Desc *desc);

s32 func_0030FEC0(struct Actor *actor, s32 key, s32 *list, s32 check) {
    struct Inv *inv;
    struct Desc *desc;
    s32 i;
    s32 id;

    if (actor->inParty != 0) {
        inv = actor->inv;
        if (inv == 0) {
            return 0;
        }
        for (i = 0; i < 6; i++) {
            id = inv->ids[i];
            if (id == key && id > 0 && id < 0x2BA) {
                desc = func_001FFBA0(&D_0042CDB0, id);
                if (desc != 0 && func_0030FD70(actor, desc) != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    if (list == 0) {
        func_00300CB0(0, &D_003D0870, 0x153);
        return 0;
    }
    for (i = 0; i < list[0]; i++) {
        id = list[i + 1];
        if (id == key && id > 0 && id < 0x2BA) {
            desc = func_001FFBA0(&D_0042CDB0, id);
            if (desc != 0) {
                if (check == 0 || (desc->flags & 1) != 0) {
                    if (func_0030FD70(actor, desc) != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
