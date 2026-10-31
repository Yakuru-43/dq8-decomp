// range: 0x273B40 0x273C30
#include "common.h"

typedef struct Node {
    struct Node *left;
    struct Node *right;
    u32 field_08;
    u32 tag;
    u32 field_10;
    char *heapStr;
} Node;

typedef struct Str {
    u32 tag;
    u32 field_10;
    char *heapStr;
} Str;

typedef struct Tree {
    u32 count;
    Node *field_04;
    u32 pad_08;
    Node *field_0C;
} Tree;

extern void func_002751A0(Node *node, void *tree);
extern void func_001007A0(void *ptr);

static inline void NodeFreeStr(Node *node)
{
    Str *str = (Str *)&node->tag;
    if (str != 0 && (node->tag & 1) != 0) {
        func_001007A0(node->heapStr);
    }
}

void func_00273B40(Tree *tree, Node **out)
{
    Node *node = *out;

    if (node == tree->field_0C) {
        Node **slot = &tree->field_0C;
        Node *v1 = node->right;
        if (v1 == 0) {
            for (;;) {
                Node *cur = *out;
                Node *par = (Node *)(cur->field_08 & ~1);
                if (cur == par->left) {
                    *out = par;
                    break;
                }
                *out = par;
            }
        } else {
            Node *v0 = v1->left;
            while (v0 != 0) {
                v1 = v0;
                v0 = v1->left;
            }
            *out = v1;
        }
        *slot = *out;
    }
    func_002751A0(node, tree->field_04);
    if ((Str *)&node->tag != 0) {
        NodeFreeStr(node);
    }
    func_001007A0(node);
    tree->count = tree->count - 1;
}
