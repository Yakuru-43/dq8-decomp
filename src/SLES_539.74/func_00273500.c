// range: 0x273500 0x2735F0
#include "common.h"

extern s32 func_00133BE0(char *a0, char *a1);

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

static inline char *NodeStr(Node *n)
{
    return (n->tag & 1) ? n->heapStr : (char *)&n->tag + 1;
}

static inline char *ItemStr(Item *item)
{
    return (item->tag & 1) ? item->heapStr : (char *)&item->tag + 1;
}

void func_00273500(Node **out, Tree *tree, Item *item)
{
    Node *node = tree->right;
    Node *best = (Node *)&tree->right;

    while (node != 0) {
        if (func_00133BE0(NodeStr(node), ItemStr(item)) < 0) {
            node = node->right;
        } else {
            best = node;
            node = node->left;
        }
    }
    if (best != (Node *)&tree->right) {
        if (func_00133BE0(ItemStr(item), NodeStr(best)) >= 0) {
            *out = best;
            return;
        }
    }
    *out = (Node *)&tree->right;
}
