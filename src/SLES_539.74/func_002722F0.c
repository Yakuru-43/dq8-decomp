// range: 0x2722F0 0x2723C0
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

typedef struct Entry {
    u32 field_00;
    Item item;
} Entry;

typedef struct Tree {
    u32 field_00;
    void *right;
} Tree;

typedef struct EntryList {
    u32 field_00;
    u32 count;
    Entry *entries;
    u32 field_0C[2];
    u32 *array;
    u32 field_18[2];
    u32 *tailArray;
    Tree tree;
} EntryList;

extern void func_00273230(void **out, Tree *tree, Item *item);
extern void func_002738F0(Tree *tree, void **hint);
extern void func_00273090(EntryList *list, Stamp stamp);

static inline u32 At(u32 *array, u32 index)
{
    return array[index];
}

static inline s32 IsValid(Stamp key)
{
    return key.word != 0;
}

void func_002722F0(EntryList *list, Stamp stamp)
{
    void *found;
    Stamp key;
    void *hint;
    u32 index;
    u32 elem;
    Entry *entry;

    key = stamp;
    if (!(IsValid(key)) != 0) {
        entry = 0;
        goto merged;
    }
    index = key.half[0];
    if (!(index < list->count)) {
        goto none;
    }
    elem = At(list->array, index);
    if (elem != key.half[1]) {
        goto none;
    }
    entry = &list->entries[index];
    goto merged;
none:
    entry = 0;
merged:
    if (entry != 0) {
        func_00273230(&found, &list->tree, &entry->item);
        hint = found;
        func_002738F0(&list->tree, &hint);
        func_00273090(list, stamp);
    }
}
