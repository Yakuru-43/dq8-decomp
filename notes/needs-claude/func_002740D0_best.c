// range: 0x2740D0 0x274230
#include "common.h"

extern "C" {

extern s32 func_00133BE0(char *a0, char *a1);
extern u8 D_003DFEB4;
extern u8 D_003DFEB8;

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

extern u32 func_00275BE0(Tree *tree, Node *last, bool cmpFlag, bool anyFlag,
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

void func_002740D0(OutRec *out, Tree *tree, Item *item)
{
    Node *found = 0;
    Node *last = (Node *)&tree->right;
    Node *node = tree->right;
    bool cmpFlag = true;
    bool anyFlag = cmpFlag;
    u32 hitNode;
    u32 missNode;

    while (node != 0) {
        last = node;
        if (func_00133BE0(ItemStr(item), NodeStr(node)) < 0) {
            node = node->left;
            cmpFlag = true;
        } else {
            found = node->left;
            cmpFlag = false;
            node = found->right;
            anyFlag = false;
        }
    }
    if (found != 0) {
        if (func_00133BE0(NodeStr(found), ItemStr(item)) >= 0) {
            out->node = hitNode = (u32)found;
            out->tag = D_003DFEB8;
            return;
        }
    }
    out->node = missNode = func_00275BE0(tree, last, cmpFlag, anyFlag, item);
    out->tag = D_003DFEB4;
}

}
