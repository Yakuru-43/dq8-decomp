// range: 0x273C30 0x273D80
#include "common.h"

extern s32 func_00133BE0(char *a0, char *a1);
extern u8 D_003DFEC4;
extern u8 D_003DFEC8;

typedef struct Node {
    struct Node *left;
    struct Node *right;
    u32 field_08;
    u32 tag;
    u32 field_10;
    char *heapStr;
} Node;

typedef struct Tree {
    u32 field_00;
    Node *right;
} Tree;

typedef struct Item {
    u32 tag;
    u32 field_04;
    char *heapStr;
} Item;

typedef struct OutRec {
    u32 node;
    u8 tag;
} OutRec;

extern u32 func_00275880(Tree *tree, Node *last, s32 cmpFlag, s32 anyFlag,
                         Item *item);

static inline char *NodeStr(Node *n)
{
    return (n->tag & 1) ? n->heapStr : (char *)&n->tag + 1;
}

static inline char *ItemStr(Item *item)
{
    return (item->tag & 1) ? item->heapStr : (char *)&item->tag + 1;
}

void func_00273C30(OutRec *out, Tree *tree, Item *item)
{
    Node *node = tree->right;
    Node *last = (Node *)&tree->right;
    Node *found = 0;
    s32 cmpFlag = 1;
    s32 anyFlag = cmpFlag;

    while (node != 0) {
        last = node;
        if (func_00133BE0(ItemStr(item), NodeStr(node)) < 0) {
            node = node->left;
            cmpFlag = 1;
        } else {
            found = node;
            cmpFlag = 0;
            node = node->right;
            anyFlag = 0;
        }
    }
    if (found != 0) {
        if (func_00133BE0(NodeStr(found), ItemStr(item)) >= 0) {
            out->node = (u32)found;
            out->tag = D_003DFEC8;
            return;
        }
    }
    out->node = func_00275880(tree, last, cmpFlag, anyFlag, item);
    out->tag = D_003DFEC4;
}
