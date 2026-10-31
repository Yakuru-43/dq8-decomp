// range: 0x272600 0x2726D0
// best attempt: CLASS structural score=37 (37 words differ, 200 vs 200 bytes)
// -O3, plain C. Also tried .cpp with bool: `used = key.word != 0; if (used ==
// false)`, `if ((key.word != 0) == false)` and `!= false` — all fold to beqz,
// never the sltu+xori+bnez of +0x1C..+0x24.
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

extern void func_00273320(void **out, Tree *tree, Item *item);
extern void func_00273B40(Tree *tree, void **out, void *node);
extern void func_00272FB0(EntryList *list, Stamp stamp);

void func_00272600(EntryList *list, Stamp stamp)
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
            if (list->array[index] == key.half[1]) {
                rec = &list->recs[index];
            } else {
                rec = 0;
            }
        } else {
            rec = 0;
        }
    } else {
        rec = 0;
    }
    if (rec != 0) {
        func_00273320(&found, &list->tree, &rec->item);
        tmp = found;
        func_00273B40(&list->tree, &tmp, found);
        func_00272FB0(list, stamp);
    }
}
