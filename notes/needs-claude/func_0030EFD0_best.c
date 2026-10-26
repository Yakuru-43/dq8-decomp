// range: 0x30EFD0 0x30F220
// best draft for func_0030EFD0 — CLASS structural score=90, 584 vs 580 B (see .md)
#include "common.h"

struct Actor {
    void *f0;
    u8 pad4[0x8];
    s16 kind;      /* 0xC */
    s16 type;      /* 0x10 */
};

struct Node {
    u8 pad0[0x18];
    struct Node *next;     /* 0x18 */
    struct Actor *actor;   /* 0x1C */
};

struct Slot {
    struct Node *node;     /* 0x0 */
    struct Actor *actor;   /* 0x4 */
    s32 kind;              /* 0x8 */
    s32 count;             /* 0xC */
    u8 ready;              /* 0x10 */
    u8 pad11[3];
};

struct Ai {
    u8 pad0[0xA8C];
    struct Node *head;     /* 0xA8C */
    u8 padA90[4];
    struct Actor *ref;     /* 0xA94 */
    u8 padA98[0xAA4 - 0xA98];
    struct Slot slots[32]; /* 0xAA4, 0x280 bytes */
    s32 nSlots;            /* 0xD24 */
    s32 nSeen;             /* 0xD28 */
    s32 total;             /* 0xD2C */
    s32 bestIdx;           /* 0xD30 */
    s32 bestVal;           /* 0xD34 */
    s32 flag;              /* 0xD38 */
};

struct Target {
    u8 pad0[0x24];
    u16 flags;             /* 0x24 */
};

extern s32 D_004523E0[];

void func_0030EFC0(void *tab, void *head);              /* extern */
struct Slot *func_0030F220(void *ai, s32 idx);          /* extern */
s32 func_0030F240(void *actor);                         /* extern */
void *func_00131188(void *dst, s32 val, s32 len);       /* extern, memset */
s32 func_0035E590(void *actor);                         /* extern */
s32 func_00297090(void *actor);                         /* extern */
s32 func_0035DBB0(void *actor, s32 a, s32 b);           /* extern */
s32 func_00342850(void *arg0);                          /* extern */

void func_0030EFD0(struct Ai *ai) {
    struct Node *node;
    struct Actor *actor;
    struct Slot *slot;
    s32 counts[6];
    s32 val;
    s32 r;
    s32 i;

    func_0030EFC0(D_004523E0, ai->head);
    func_00131188(&ai->slots, 0, 0x280);
    ai->nSlots = 0;
    ai->nSeen = 0;
    node = ai->head;
    func_00131188(counts, 0, 0x18);
    ai->bestVal = 0xFFFF;
    do {
        if (node == 0) {
            break;
        }
        actor = node->actor;
        if (actor == 0) {
            break;
        }
        if (func_0035E590(actor) == 1) {
            if (func_0030F240(actor) == 0) {
                continue;
            }
            if (func_00297090(actor) <= 0) {
                continue;
            }
            ai->flag = 1;
            goto add;
        }
        if (actor->type == 1) {
            continue;
        }
    add:
        val = ai->nSlots + ai->nSeen;
        if (func_0035E590(actor) == 0) {
            r = func_00297090(actor);
            if (0 < r) {
                if (!(ai->bestVal < r)) {
                    ai->bestVal = r;
                }
            }
            if (actor == ai->ref) {
                ai->bestIdx = val;
            }
            ai->nSlots = ai->nSlots + 1;
        } else {
            ai->nSeen = ai->nSeen + 1;
        }
        slot = func_0030F220(ai, val);
        slot->node = node;
        slot->actor = actor;
        slot->kind = actor->kind;
        counts[actor->type] = counts[actor->type] + 1;
    } while ((node = node->next) != 0);

    ai->total = ai->nSlots + ai->nSeen;
    for (i = 0; i < ai->total; i = i + 1) {
        slot = func_0030F220(ai, i);
        actor = slot->actor;
        slot->count = counts[actor->type];
        slot->ready = func_0035DBB0(actor, 0, 1);
    }
    ai->flag = 1;
    for (i = ai->nSlots; i < ai->total; i = i + 1) {
        slot = func_0030F220(ai, i);
        r = func_00342850(slot->actor->f0);
        if (0 < r && (((struct Target *)r)->flags & 2) != 0) {
            continue;
        }
        ai->flag = 0;
        break;
    }
}
