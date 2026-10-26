// range: 0x30EFD0 0x30F220
#include "common.h"

struct Node {
    char pad0[0x18];
    struct Node *next;
    void *item;
};

struct Item {
    s32 f0;
    char pad4[8];
    s16 fC;
    char padE[2];
    s16 f10;
};

struct Flags {
    char pad0[0x24];
    u16 f24;
};

struct Slot {
    struct Node *node;
    struct Item *item;
    s32 f8;
    s32 fC;
    u8 f10;
    char pad11[3];
};

struct Out {
    char pad0[0xA8C];
    s32 fA8C;
    s32 fA90;
    struct Item *fA94;
    char padA98[0xAA4 - 0xA98];
    struct Slot slots[0x280 / 0x14];
    s32 fD24;
    s32 fD28;
    s32 fD2C;
    s32 fD30;
    s32 fD34;
    s32 fD38;
};

extern M2C_UNK D_004523E0 __attribute__((section(".data")));

void func_0030EFC0(void *, s32);                       /* extern */
void func_00131188(void *, s32, s32);                  /* extern */
s32 func_0035E590(void *);                             /* extern */
s32 func_00297090(void *);                             /* extern */
s32 func_0035DBB0(void *, s32, s32);                   /* extern */
s32 func_0030F240(void *);                             /* extern */
struct Slot *func_0030F220(struct Out *, s32);         /* extern */
struct Flags *func_00342850(s32);                      /* extern */

void func_0030EFD0(struct Out *out) {
    u32 hist[6];
    struct Node *node;
    struct Item *item;
    s32 idx;
    s32 kind;
    s32 count;
    struct Slot *slot;
    u32 newp;
    s32 score;
    s32 ok;
    s32 i;
    struct Flags *flags;

    func_0030EFC0(&D_004523E0, out->fA8C);
    func_00131188(out->slots, 0, 0x280);
    out->fD24 = 0;
    out->fD28 = 0;
    node = (struct Node *)out->fA8C;
    func_00131188(hist, 0, 0x18);
    out->fD34 = 0xFFFF;
    while (node != 0) {
        node = node->next;
        if (node == 0) {
            break;
        }
        item = node->item;
        if (item == 0) {
            break;
        }
        kind = func_0035E590(item);
        if (kind == 1) {
            if (func_0030F240(item) == 0) {
                continue;
            }
            if (func_00297090(item) <= 0) {
                continue;
            }
            out->fD38 = 1;
        } else {
            if (item->f10 == 1) {
                continue;
            }
        }
        idx = out->fD24 + out->fD28;
        if (func_0035E590(item) == 0) {
            score = func_00297090(item);
            if (0 < score && score <= out->fD34) {
                out->fD34 = score;
            }
            if (item == out->fA94) {
                out->fD30 = idx;
            }
            out->fD24 = out->fD24 + 1;
        } else {
            out->fD28 = out->fD28 + 1;
        }
        slot = func_0030F220(out, idx);
        slot->node = node;
        slot->item = item;
        slot->f8 = item->fC;
        hist[item->f10] = hist[item->f10] + 1;
    }
    out->fD2C = out->fD24 + out->fD28;
    for (i = 0; i < out->fD2C; i++) {
        slot = func_0030F220(out, i);
        item = slot->item;
        count = hist[item->f10];
        slot->fC = count;
        newp = func_0035DBB0(item, 0, 1);
        slot->f10 = newp;
    }
    out->fD38 = 1;
    for (idx = out->fD24; idx < out->fD2C; idx++) {
        slot = func_0030F220(out, idx);
        item = slot->item;
        flags = func_00342850(item->f0);
        ok = flags != 0;
        if (ok != 0) {
            ok = (flags->f24 & 2) != 0;
        }
        if (ok == 0) {
            out->fD38 = 0;
            break;
        }
    }
}
