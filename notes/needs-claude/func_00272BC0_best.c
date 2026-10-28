// range: 0x272BC0 0x272C90
// best attempt: CLASS structural score=18 (18 words differ, 200 vs 200 bytes)
// -O3, plain C. Clone of func_00272600_best.c (the twin) with the elem arms
// swapped. Frame, prologue (sw a1/lwc1/sd/sq/swc1), slots (stamp 0x20,
// tmp 0x24, key 0x28, found 0x2C) and everything from +0x5C on match except
// the three jal relocs and the $v0/$a2 choice in the call2 block.
#include "common.h"

typedef union Stamp {
    u32 word;
    u16 half[2];
} Stamp;

typedef struct Item {
    u32 tag;
    u32 field_04;
    char *heapStr;
} Item;

typedef struct Rec {
    u32 field_00;
    Item item;
} Rec;

typedef struct Tree {
    u32 field_00;
    void *right;
} Tree;

typedef struct EntryList {
    u32 field_00;
    u32 count;
    Rec *recs;
    u32 field_0C;
    u32 field_10;
    u32 *array;
    u32 field_18;
    u32 tailCount;
    u32 *tailArray;
    Tree tree;
} EntryList;

extern void func_00273410(void **out, Tree *tree, Item *item);
extern void func_00273D90(Tree *tree, void **out, void *node);
extern void func_00272ED0(EntryList *list, Stamp stamp);

static inline u32 At(u32 *array, u32 index)
{
    return array[index];
}

void func_00272BC0(EntryList *list, Stamp stamp)
{
    void *found;
    Stamp key;
    void *tmp;
    Rec *rec;
    u32 index;

    key = stamp;
    if (key.word != 0) {
        index = key.half[0];
        if (index < list->count) {
            if (At(list->array, index) != key.half[1]) {
                rec = 0;
            } else {
                rec = &list->recs[index];
            }
        } else {
            rec = 0;
        }
    } else {
        rec = 0;
    }
    if (rec != 0) {
        func_00273410(&found, &list->tree, &rec->item);
        tmp = found;
        func_00273D90(&list->tree, &tmp, found);
        func_00272ED0(list, stamp);
    }
}
