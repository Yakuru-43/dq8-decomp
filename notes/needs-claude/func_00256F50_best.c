// range: 0x256F50 0x2571D0
// best C for func_00256F50, 2026-11-03 factory-2 (attempt 1, CLASS structural 147)
#include "common.h"

typedef struct {
    s16 flag;
    s16 f2;
    s32 f4;
    s32 f8;
    s32 fC;
} Item; /* 20 bytes */

typedef struct {
    s16 flag;
    s16 f2;
    s32 f4;
    s32 f8;
} Fix; /* 12 bytes */

typedef struct {
    Item *items;
    s16 count;
} Obj;

typedef struct {
    s32 start;
    s32 len;
} Group;

extern void func_00132330(void *base, s32 n, s32 size, void *cmp);
extern s32 func_002571D0(s32 *a, s32 *b);
extern s32 func_00257200(s32 *a, s32 *b);
extern void func_0014DF10(void *obj, s32 arg1, s32 arg2);

static s32 FlagAt(Obj *obj, s32 i) {
    if (i < 0) {
        return 0;
    }
    if (i >= obj->count) {
        return 0;
    }
    return obj->items[i].flag;
}

s32 func_00256F50(Obj *obj, void *obj2, s32 count2, s32 mode) {
    Group groups[88];
    Group *g;
    Group *gEnd;
    Fix *fix;
    Item *item;
    s32 nGroups;
    s32 i;
    s32 j;
    s32 k;
    s32 total;
    s32 found;
    s32 w8;

    if (obj->items == 0) {
        return -1;
    }
    gEnd = groups + 88;
    for (g = groups; g < gEnd; g++) {
        g->start = -1;
        g->len = 0;
    }
    nGroups = 0;
    for (i = 0; i < obj->count; i++) {
        if (FlagAt(obj, i) == 0) {
            g = &groups[nGroups];
            g->start = i;
            g->len = 1;
            for (j = i + 1; j < obj->count; j++) {
                if (FlagAt(obj, j) != 0) {
                    break;
                }
                g->len++;
                i++;
            }
            nGroups++;
            i++;
        }
    }
    found = -1;
    if (mode == 0) {
        func_00132330(groups, nGroups, 8, func_00257200);
        for (k = 0; k < nGroups; k++) {
            if (groups[k].len >= count2) {
                found = groups[k].start;
                break;
            }
        }
    } else if (mode == 1) {
        func_00132330(groups, nGroups, 8, func_002571D0);
        for (k = 0; k < nGroups; k++) {
            if (groups[k].len >= count2) {
                found = groups[k].start + groups[k].len - count2;
                break;
            }
        }
    }
    if (found < 0) {
        return -1;
    }
    item = &obj->items[found];
    w8 = item->f8;
    fix = (Fix *)item;
    total = 0;
    for (k = 0; k < count2; k++) {
        if (fix->flag != 0) {
            break;
        }
        fix->flag = 1;
        total += 0x800;
        fix++;
    }
    func_0014DF10(obj2, w8, total);
    return found;
}
