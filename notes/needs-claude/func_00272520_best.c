// range: 0x272520 0x272600
// Look up `tail` in the object's tree: build a temporary key string, grow it
// to the tail's length, splice the tail in through the shared splice worker,
// search the tree, free the key, and return the best node's field.
// BEST DRAFT (not committed): every word from +0x0C to the loop end and the
// tail beql pair match; key lands at 0x50(sp), original has 0x58, and CW
// tail-outlines the free call. See func_00272520.md.
#include "common.h"

struct Tree {
    /* 0x00 */ u32 field_00;
    /* 0x04 */ struct Node *right;
};

struct Node {
    struct Node *left;
    struct Node *right;
    u32 field_08;
    u32 tag;
    u32 field_10;
    char *heapStr;
    u32 field_18;
};

struct Item {
    /* 0x00 */ u32 tag;
    /* 0x04 */ u32 field_04;
    /* 0x08 */ char *heapStr;
    /* 0x0C */ u32 field_0C;
};

struct Map {
    /* 0x00 */ u8 gap_00[0x24];
    /* 0x24 */ struct Tree tree;
};

extern u32 func_001341D8(u32);
extern void func_001080E0(void *, u32);
extern void func_00107100(void *, u32, u32, u32, u32, s8);
extern void func_001007A0(void *node);
extern void func_00273320(struct Node **out, struct Tree *tree, struct Item *item);

void func_00272520(u32 *result, struct Map *map, u32 tail)
{
    struct Item key;
    struct Node *found;
    u8 flag[4];
    u32 *p;
    u32 i;
    u32 len;

    p = (u32 *)&key;
    for (i = 0; i < 3; i++) {
        p[i] = 0;
    }
    len = func_001341D8(tail);
    func_001080E0(&key, len);
    func_00107100(&key, 0, 0, tail, tail + len, flag[0]);
    func_00273320(&found, &map->tree, &key);
    if ((key.tag & 1) != 0) {
        func_001007A0(key.heapStr);
    }
    if (found == (struct Node *)&map->tree.right) {
        *result = 0;
    } else {
        *result = found->field_18;
    }
}
