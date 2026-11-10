// range: 0x2739E0 0x273B30
#include "common.h"

extern s32 func_00133BE0(char *a0, char *a1);
extern u8 D_003DFECC;
extern u8 D_003DFED0;

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

extern u32 func_002756D0(Tree *tree, Node *last, s32 cmpFlag, s32 anyFlag,
                         Item *item);

typedef struct OutRec {
    u32 node;
    u8 tag;
} OutRec;

static inline char *NodeStr(Node *n)
{
    return (n->tag & 1) ? n->heapStr : (char *)&n->tag + 1;
}

static inline char *ItemStr(Item *item)
{
    return (item->tag & 1) ? item->heapStr : (char *)&item->tag + 1;
}

void func_002739E0(OutRec *out, Tree *tree, Item *item)
{
    Node *node = tree->right;
    Node *last = (Node *)&tree->right;
    Node *found = 0;
    s32 cmpFlag = 1;
    s32 anyFlag = cmpFlag;

    while (node != 0) {
        last = node;
        if (func_00133BE0(NodeStr(node), ItemStr(item)) < 0) {
            node = node->left;
            cmpFlag = 1;
        } else {
            found = node->left;
            cmpFlag = 0;
            node = found->right;
            anyFlag = 0;
        }
    }
    if (found != 0) {
        if (func_00133BE0(ItemStr(item), NodeStr(found)) >= 0) {
            out->node = (u32)found;
            out->tag = D_003DFED0;
            return;
        }
    }
    out->node = func_002756D0(tree, last, cmpFlag, anyFlag, item);
    out->tag = D_003DFECC;
}
