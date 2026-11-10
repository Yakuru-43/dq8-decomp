// range: 0x21E190 0x21E340
// best draft, 2026-11-01 factory-2; CLASS structural score=107, 408 vs 432 bytes
#include "common.h"

typedef struct Sub Sub;
typedef struct Item Item;

struct Sub {
    s32 count;
    Item *items;
    s32 f8;
    s32 padC[2];
};

struct Item {
    s32 f0;
    s32 pad4[8];
};

typedef struct {
    s32 count;
    Sub *items;
} List;

extern s32 func_00166760(char *arg0);
extern s32 func_00133F78(s32, s32);
extern List *D_003E09D4;
extern void *D_003E09DC;

s32 func_0021E190(char *arg0, s32 arg1) {
    List *list;
    Sub *cursor;
    Sub *sub;
    Item *cursor2;
    Item *item;
    s32 p;
    s32 index;
    s32 j;

    if (D_003E09DC == NULL) {
        return 0;
    }
    if (arg1 < 2) {
        return 0;
    }
    func_00166760(arg0);
    p = func_00166760(arg0 + 8);
    list = D_003E09D4;
    cursor = list->items;
    if (p != 0) {
        index = 0;
        while (index < list->count) {
            if (cursor->f8 != 0 && func_00133F78(p, cursor->f8) == 0) {
                goto have_sub;
            }
            index++;
            cursor++;
        }
        index = -1;
    } else {
        index = -1;
    }
have_sub:
    if (index < 0) {
        sub = 0;
    } else if (index >= list->count) {
        sub = 0;
    } else {
        sub = list->items + index;
    }
    if (sub == 0) {
        return 0;
    }
    if (p != 0) {
        cursor2 = sub->items;
        j = 0;
        while (j < sub->count) {
            if (cursor2->f0 != 0 && func_00133F78(p, cursor2->f0) == 0) {
                goto have_item;
            }
            j++;
            cursor2++;
        }
        j = -1;
    } else {
        j = -1;
    }
have_item:
    if (j < 0) {
        item = 0;
    } else if (j >= sub->count) {
        item = 0;
    } else {
        item = sub->items + j;
    }
    if (item == 0) {
        return 0;
    }
    M2C_FIELD(D_003E09DC, Item **, 0) = item;
    M2C_FIELD(D_003E09DC, Sub **, 8) = sub;
    return 1;
}
