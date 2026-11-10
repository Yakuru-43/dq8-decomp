// range: 0x29CE00 0x29D100
// BEST attempt: CLASS structural score=113. NOTE: Entry needs `char pad0E[2]`
// between id0C and key10 (asm reads lh 0x10/0x12, this draft reads 0xE/0x10);
// attempt 2 with that pad + else-if chain + counter temp scored 135 — keep the
// `continue` dispatch below, it placed blocks correctly.
#include "common.h"

struct Node0029CE00 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    char pad5;
    u16 u6;
    struct Node0029CE00 *f8;
    struct Node0029CE00 *fC;
    u16 u10;
    struct Node0029CE00 *f14;
    struct Node0029CE00 *f18;
    s32 f1C;
};

struct Owner0029CE00 {
    char pad0[0x48];
    struct Node0029CE00 nodes[32];
    struct Node0029CE00 free;
    struct Node0029CE00 sorted;
    struct Node0029CE00 *head488;
    s32 counter48C;
    char pad490[0x528 - 0x490];
    u8 matrix[36];
    s32 pickA[2][4];
    s32 pickB[2][4];
};

struct Entry0029CE00 {
    char pad0[0xC];
    s16 id0C;
    s16 key10;
    s16 key12;
    char pad14[0x54C - 0x14];
    s32 f54C;
};

extern void *func_0029D100(void *arg0, void *arg1);
extern s32 func_00359620(void *name, s32 id, struct Entry0029CE00 **buf, s32 max,
                         s32 a, s32 b, s32 c, s32 d, s64 e);
extern s32 func_00201760(struct Entry0029CE00 *entry, s32 arg1);
extern struct Node0029CE00 D_003CB150 __attribute__((section(".data")));
extern char D_00421AD0 __attribute__((section(".data")));

void func_0029CE00(struct Owner0029CE00 *owner)
{
    struct Entry0029CE00 *buf[32];
    struct Entry0029CE00 *entry;
    s32 round;
    s32 count;
    s32 cat;
    s32 idx;
    s32 flag;
    s32 key10;
    s32 key12;
    s32 better;
    s32 best;
    s32 score;
    s32 row;
    s32 col;
    s32 slot;

    owner->counter48C = owner->counter48C + 1;
    if (owner->counter48C < 0) {
        owner->counter48C = 0;
    }
    for (row = 0; row < 6; row++) {
        for (col = 0; col < 6; col++) {
            owner->matrix[6 * row + col] = 1;
        }
    }
    for (slot = 0; slot < 32; slot++) {
        func_0029D100(&owner->nodes[slot], &D_003CB150);
    }
    func_0029D100(&owner->free, &D_003CB150);
    owner->free.f8 = 0;
    owner->free.f14 = 0;
    owner->free.fC = &owner->sorted;
    func_0029D100(&owner->sorted, &D_003CB150);
    owner->free.f18 = &owner->sorted;
    owner->sorted.f8 = &owner->free;
    owner->sorted.f14 = &owner->free;
    owner->sorted.u6 = 0xFFFF;
    owner->sorted.u10 = 0xFFFF;
    for (round = 0; round < 2; round++) {
        flag = 1;
        count = func_00359620(&D_00421AD0, (round != 0) ? 0 : flag, buf, 0x20,
                              flag, 0, 0, -1, 0);
        for (cat = 0; cat < 4; cat++) {
            if (cat == 2) {
                best = -1;
                owner->pickA[round][cat] = -1;
                owner->pickB[round][cat] = -1;
                idx = 0;
                while (idx < count) {
                    entry = buf[idx];
                    score = func_00201760(entry, 0);
                    if (score < best || best < 0) {
                        owner->pickA[round][cat] = entry->id0C;
                        owner->pickB[round][cat] = entry->f54C;
                        best = func_00201760(entry, 0);
                    }
                    idx++;
                }
                continue;
            }
            if (cat == 3) {
                owner->pickA[round][cat] = -1;
                owner->pickB[round][cat] = -1;
                continue;
            }
            key10 = -1;
            key12 = key10;
            owner->pickA[round][cat] = key10;
            owner->pickB[round][cat] = key10;
            idx = 0;
            while (idx < count) {
                entry = buf[idx];
                better = 0;
                if (key10 < 0 || key12 < 0) {
                    better = 1;
                }
                score = entry->key10;
                if (key10 < score) {
                    better = 1;
                }
                if (score == key10 && key12 < entry->key12) {
                    better = 1;
                }
                if (better != 0) {
                    owner->pickA[round][cat] = entry->id0C;
                    owner->pickB[round][cat] = entry->f54C;
                    key12 = entry->key12;
                    key10 = entry->key10;
                }
                idx++;
            }
        }
    }
    owner->head488 = &owner->free;
}
