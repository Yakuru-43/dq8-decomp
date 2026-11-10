// Best attempt (attempt 2): CLASS structural score=92, 356 vs 380 bytes.
// Register/alloc issues in notes/needs-claude/func_0014CB70.md.
// range: 0x14CB70 0x14CCF0
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct Item {
    struct Item *next;    /* 0x00 */
    u16 type;             /* 0x04 */
    u16 width;            /* 0x06 */
    u8 size;              /* 0x08 */
} Item;

typedef struct Group {
    u8 pad_00[0x70];
    s32 count;            /* 0x70 */
    Item *items;          /* 0x74 */
    u8 pad_78[0x08];
    struct Group *next;   /* 0x80 */
} Group;

typedef struct Obj {
    u8 pad_00[0x20];
    s32 numGroups;        /* 0x20 */
    Group *groups;        /* 0x24 */
    u8 pad_28[0x04];
    u32 f_2C;             /* 0x2C */
    u32 f_30;             /* 0x30 */
    u32 f_34;             /* 0x34 */
} Obj;

typedef struct Out {
    Group *group;         /* 0x00 */
    u32 f_04;             /* 0x04 */
    u32 f_08;             /* 0x08 */
    u32 f_0C;             /* 0x0C */
    s32 count;            /* 0x10 */
    s32 total;            /* 0x14 */
    s32 sum3;             /* 0x18 */
    s32 sum2;             /* 0x1C */
} Out;

void func_0014CB70(Out *out, Obj **a1, s32 idx) {
    Obj *obj = *a1;
    Obj *o2;
    u32 f30;
    u32 f2C;
    u32 f34;
    s32 count;
    Group *group;
    s32 i;
    Item *item;
    s32 m;
    s32 x;
    s32 total;
    s32 sum3;
    s32 sum2;
    s32 n;

    if (obj == 0) {
        out->group = 0;
        out->f_04 = 0;
        out->f_08 = f30;
        out->f_0C = 0;
        out->count = 0;
        out->total = 0;
        out->sum3 = 0;
        out->sum2 = 0;
        return;
    }
    count = 0;
    if (obj != 0) {
        count = obj->numGroups;
    }
    if (idx < 0 || idx >= count) {
        out->group = 0;
        out->f_04 = 0;
        out->f_08 = f30;
        out->f_0C = 0;
        out->count = 0;
        out->total = 0;
        out->sum3 = 0;
        out->sum2 = 0;
        return;
    }
    group = obj->groups;
    i = 0;
    while (group != 0) {
        if (i == idx) {
            break;
        }
        group = group->next;
        i++;
    }
    o2 = *a1;
    if (o2 != 0) {
        f2C = obj->f_2C;
    } else {
        f2C = 0;
    }
    f30 = o2->f_30;
    f34 = obj->f_34;
    count = group->count;
    item = group->items;
    total = 0;
    sum3 = 0;
    sum2 = 0;
    for (n = 0; n < count; n++) {
        m = item->width * item->size;
        x = m - 2;
        switch (item->type) {
        case 3:
            sum3 += m / 3;
            break;
        case 4:
            sum2 += x / 2;
            break;
        default:
            break;
        }
        total += m;
        item = item->next;
    }
    out->group = group;
    out->f_04 = f2C;
    out->f_08 = f30;
    out->f_0C = f34;
    out->count = count;
    out->total = total;
    out->sum3 = sum3;
    out->sum2 = sum2;
}
