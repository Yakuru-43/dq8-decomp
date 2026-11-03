// range: 0x2756D0 0x275880
// tree::insert's node creation (map<string, u32>): check the length, allocate
// a node, copy-construct its value (heap strings are cleared, reserved and
// spliced in, inline ones copied as three words), link it under the parent
// on the chosen side, count it, rebalance from the root and update leftmost.
#include "common.h"

extern "C" {

extern void *func_00100970(u32);
extern void func_001080E0(void *, u32);
extern void func_00107100(void *, u32, u32, u32, u32, s8);
extern void func_00275D90(void *, u32);
extern void func_0012EFC8(u32, char *);
extern void func_0012D4A8(void);

extern u32 D_003A0788 __attribute__((section(".data")));
extern char D_003C9FB0[];   /* "tree::insert length error\n" */
extern char D_003CA030[];   /* "Memory allocation failure" */

struct Str {
    u32 flags;
    u32 len;
    u32 ptr;
};

/* An inline string's three words, copied through the FPU like the original. */
struct StrWords {
    f32 w[3];
};

struct Value {
    Str key;
    u32 data;
};

struct Node {
    Node *left;
    Node *right;
    u32 parent;     /* parent pointer, colour in bit 0 */
    Value value;
};

struct Tree {
    u32 size;
    u32 root;
    u32 field08;
    Node *leftmost;
};

static inline void warn(char *msg) {
    func_0012EFC8(*(u32 *)(D_003A0788 + 0xC), msg);
    func_0012D4A8();
}

static inline u32 max_size() { return 0xFFFFFFFF; }

Node *func_002756D0(Tree *tree, u32 parent, s32 left, s32 leftmost_too,
                    const Value &v) {
    Node *n;
    Value *buf;
    u32 i;
    u8 flag[4];

    if (tree->size > max_size() - 1) {
        warn(D_003C9FB0);
    }
    n = (Node *)func_00100970(sizeof(Node));
    if (n == 0) {
        warn(D_003CA030);
    }
    buf = &n->value;
    if (buf != 0) {
        if (v.key.flags & 1) {
            for (i = 0; i < 3; i++) {
                ((u32 *)buf)[i] = 0;
            }
            func_001080E0(buf, v.key.len);
            func_00107100(buf, 0, 0, v.key.ptr, v.key.ptr + v.key.len, flag[0]);
        } else {
            *(StrWords *)buf = *(const StrWords *)&v;
        }
        buf->data = v.data;
    }
    n->right = 0;
    n->left = 0;
    n->parent = parent | (n->parent & 1);
    if (left) {
        ((Node *)parent)->left = n;
    } else {
        ((Node *)parent)->right = n;
    }
    tree->size++;
    func_00275D90(n, tree->root);
    if (leftmost_too) {
        tree->leftmost = n;
    }
    return n;
}

}
