// range: 0x29B1A0 0x29B3C0
// Best attempt 2026-10-27 factory-2: CLASS structural score=101 (520 vs 536).
// See func_0029B1A0.md for the remaining diff (register allocation).
#include "common.h"

struct Kind0029B1A0 {
    char pad[0x75];
    u8 b75;
};

struct Data0029B1A0 {
    char pad[0x20];
    u32 flags;
};

struct Sub0029B1A0 {
    char pad[0x8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    char pad18[0x284 - 0x18];
    struct Kind0029B1A0 *kind;
    struct Data0029B1A0 *data;
};

struct Unit0029B1A0 {
    char pad[0xE0];
    struct Sub0029B1A0 sub;
};

struct Owner0029B1A0 {
    char pad[0x54C];
    s32 ids[8];
    s32 vals[8];
};

struct Entry0029B1A0 {
    char pad[0xC];
    s16 val;
    s16 padE;
    s16 x;
    s16 y;
    char pad14[0x54C - 0x14];
    s32 key;
};

extern u8 func_0029CAF0(struct Owner0029B1A0 *owner, struct Unit0029B1A0 *unit);
extern s32 func_0035E590(struct Unit0029B1A0 *unit);
extern struct Entry0029B1A0 *func_00359CF0(struct Entry0029B1A0 *list, s32 id);
extern s32 func_00201760(struct Entry0029B1A0 *entry, s32 arg);
extern u32 func_0035E320(struct Entry0029B1A0 *entry);
extern void func_00292CB0(struct Owner0029B1A0 *owner, struct Unit0029B1A0 *unit);
extern void func_00296930(struct Owner0029B1A0 *owner);
extern void func_002969F0(struct Owner0029B1A0 *owner);
extern void func_00296A50(struct Owner0029B1A0 *owner);
extern struct Entry0029B1A0 *FindEntry__FP5Entryii(struct Entry0029B1A0 *list,
                                                   s32 x, s32 y);
extern struct Entry0029B1A0 D_00421AD0[] __attribute__((section(".data")));

s32 func_0029B1A0(struct Owner0029B1A0 *owner, struct Unit0029B1A0 *unit)
{
    s32 want;
    struct Entry0029B1A0 *entry;
    struct Sub0029B1A0 *sub;
    s32 kind;
    s32 *idSlot;
    s32 *valSlot;
    s32 idx;
    struct Owner0029B1A0 *sel;

    sub = &unit->sub;
    if ((unit->sub.data->flags & 0x400) == 0) {
        return 0;
    }
    if (sub->f8 != 3 || sub->fC != 1) {
        return 0;
    }
    if (func_0029CAF0(owner, unit) == 0) {
        return 0;
    }
    idx = func_0035E590(unit);
    kind = sub->kind->b75;
    sel = (struct Owner0029B1A0 *)((char *)owner + idx * 0x10);
    idSlot = &sel->ids[kind];
    valSlot = &sel->vals[kind];
    want = *valSlot;
    if (kind != 0) {
        entry = func_00359CF0(D_00421AD0, *idSlot);
        if (entry != 0) {
            if (entry->key == want) {
                if (func_00201760(entry, 0) > 0) {
                    if ((func_0035E320(entry) & 4) == 0) {
                        sub->f10 = entry->x;
                        sub->f14 = entry->y;
                        return 1;
                    }
                }
            }
        }
    }
    func_00292CB0(owner, unit);
    switch (kind) {
    case 1:
        func_00296A50(owner);
        break;
    case 2:
        func_002969F0(owner);
        break;
    case 3:
        func_00296930(owner);
        break;
    default:
        *idSlot = -1;
        *valSlot = -1;
        return 0;
    }
    entry = FindEntry__FP5Entryii(D_00421AD0, sub->f10, sub->f14);
    if (entry == 0) {
        *idSlot = -1;
        *valSlot = -1;
    } else {
        *idSlot = entry->val;
        *valSlot = entry->key;
    }
    return 1;
}
