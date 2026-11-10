// range: 0x29DEC0 0x29E150
#include "common.h"

struct Kind0029DEC0 {
    char pad[0x60];
    u8 b60;
};

struct Node0029DEC0 {
    u8 b0;
    u8 b1;
    u8 b2;
    char pad3[3];
    u16 u6;
    void *f8;
    void *fC;
    u16 u10;
    char pad12[2];
    struct Node0029DEC0 *f14;
    struct Node0029DEC0 *f18;
    void *f1C;
};

struct Head0029DEC0 {
    char pad[6];
    u16 u6;
    char pad8[4];
    struct Node0029DEC0 *tail;
};

struct Owner0029DEC0 {
    char pad0[0x48];
    struct Node0029DEC0 nodes[32];
    struct Node0029DEC0 list;
    char pad468[0x20];
    struct Head0029DEC0 *head;
};

struct Target0029DEC0 {
    s32 f00;
    char pad04[0xC];
    union Key0029DEC0 k10;
    char pad13[0xC0];
    struct Kind0029DEC0 *fD4;
    char padD8[8];
    s32 fE0;
    char padE4[0x5C];
    s32 f140;
    s32 f144;
    u8 b148;
    char pad149[7];
    u8 b150;
    char pad151[0x203];
    s32 f354;
    char pad358[0xC];
    s32 f364;
    char pad368[8];
    u8 b370;
    char pad371[3];
    s32 f374;
    char pad378[0x1F7];
    u8 b56F;
};

struct Type0029DEC0 {
    char pad[0xC];
    s16 u0C;
};

extern struct Target0029DEC0 *func_00359CF0(void *pool, s32 type);
extern void func_0029DE30(struct Owner0029DEC0 *owner, struct Target0029DEC0 *target, s32 flag);
extern s32 func_00298520(void *owner, s32 val);
extern void func_00300CB0(s32 code, void *file, s32 line);
extern void func_0035B1B0(void *pool);
extern void func_0035B0B0(void *pool);
extern void func_0029C140(void *owner, struct Target0029DEC0 *target, s32 idx, s32 arg3);
extern void func_0029E150(void *owner, struct Target0029DEC0 *target);
extern char D_00421AD0 __attribute__((section(".data")));
extern char D_003CBEA0;

void func_0029DEC0(struct Owner0029DEC0 *owner, struct Type0029DEC0 *arg1, s32 arg2, s32 arg3,
                   s32 arg4)
{
    struct Target0029DEC0 *target;
    struct Node0029DEC0 *node;
    struct Head0029DEC0 *head;
    struct Node0029DEC0 *scan;
    struct Node0029DEC0 *next;
    struct Kind0029DEC0 *kind;
    s32 i;
    s32 key;
    u16 val6;

    if (arg1 == 0) {
        return;
    }
    target = func_00359CF0(&D_00421AD0, arg1->u0C);
    if (target == 0) {
        return;
    }
    func_0029DE30(owner, target, 0);
    node = 0;
    for (i = 0; i < 32; i++) {
        next = &owner->nodes[i];
        if (next->f1C == 0) {
            node = next;
            break;
        }
    }
    if (node == 0) {
        func_00300CB0(0, &D_003CBEA0, 0x782);
        return;
    }
    target->b370 = 0;
    target->f374 = 0;
    target->b150 = 0;
    target->f354 = 0;
    if (target->k10.i16 != 0) {
        target->f364 = func_00298520(owner, target->f00);
    }
    head = owner->head;
    val6 = head->u6;
    node->f8 = head;
    node->fC = head->tail;
    head->tail->f8 = node;
    head->tail = node;
    key = (target->k10.b.lo << 8) | target->k10.b.hi;
    scan = &owner->list;
    next = scan->f18;
    while (next != 0) {
        scan = next;
        if (next->u10 == 0xFFFF) {
            break;
        }
        if (key < next->u10) {
            break;
        }
        next = scan->f18;
    }
    node->f14 = scan->f14;
    node->f18 = scan;
    scan->f14->f18 = node;
    scan->f14 = node;
    node->b0 = 1;
    node->b1 = 0;
    node->b2 = 0;
    node->u6 = val6;
    node->u10 = key;
    node->f1C = target;
    target->b56F = arg2;
    target->fE0 = -1;
    target->f140 = 0;
    target->f144 = 0;
    target->b148 = 0;
    target->f354 = 0x200;
    if (arg3 == 0) {
        return;
    }
    kind = target->fD4;
    if (kind != 0) {
        if (arg4 != 0 || kind->b60 != 2) {
            target->fE0 = -1;
            target->f140 = 0;
            target->f144 = 1;
            target->b148 = 1;
            func_0035B1B0(&D_00421AD0);
            target->f354 = 0;
            func_0029C140(owner, target, 1, 1);
            func_0035B0B0(&D_00421AD0);
            func_0029E150(owner, target);
        }
    }
    if (kind->b60 != 2) {
        return;
    }
    if (arg4 != 0) {
        return;
    }
    target->fE0 = -1;
    target->f140 = 0;
    target->f144 = 1;
    target->b148 = 1;
    target->f354 = 0;
}
