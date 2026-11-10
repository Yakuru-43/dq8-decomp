// range: 0x29D200 0x29D3A0
#include "common.h"

struct Target0029D200 {
    char pad[0x10];
    u8 kind_hi;
    char pad11[1];
    u8 kind_lo;
};

struct Node0029D200 {
    u8 b0;
    u8 b1;
    u8 b2;
    char pad3[3];
    u16 key;
    struct Node0029D200 *prev;
    struct Node0029D200 *next;
    u16 key10;
    char pad12[2];
    struct Node0029D200 *f14;
    struct Node0029D200 *f18;
    struct Target0029D200 *target;
};

struct Owner0029D200 {
    char pad[0x48];
    struct Node0029D200 pool[32];
    struct Node0029D200 list;
};

extern s32 func_00132D38(void);
extern void func_00300CB0(s32 cond, char *file, s32 line);
extern char D_003CBEA0[];

/* take a free slot and splice it into the target's list/tree */
struct Node0029D200 *func_0029D200(struct Owner0029D200 *owner,
                                   struct Target0029D200 *target, s32 key)
{
    struct Node0029D200 *node;
    struct Node0029D200 *cursor;
    struct Node0029D200 *root;
    struct Node0029D200 *child;
    s32 i;
    s32 v1;
    u16 key10;
    s32 r;

    i = 0;
    while (i < 32) {
        node = &owner->pool[i];
        if (node->target == 0) {
            break;
        }
        i++;
    }
    if (i >= 32) {
        func_00300CB0(0, D_003CBEA0, 0xAA0);
        return 0;
    }
    v1 = (u16)key;
    cursor = &owner->list;
    while ((child = cursor->next) != 0) {
        cursor = child;
        if (v1 < cursor->key) {
            break;
        }
    }
    node->prev = cursor->prev;
    node->next = cursor;
    cursor->prev->next = node;
    cursor->prev = node;
    key10 = (u16)((target->kind_hi << 8) | target->kind_lo);
    root = &owner->list;
    while ((child = root->f18) != 0) {
        root = child;
        v1 = (s32)child->key10;
        if (v1 == 0xFFFF) {
            break;
        }
        if (v1 == (s32)key10) {
            r = func_00132D38();
            v1 = r & 0xFF;
            if (r < 0) {
                if (v1 != 0) {
                    v1 -= 0x100;
                }
            }
            if (v1 < 0x80) {
                break;
            }
            continue;
        }
        if ((s32)key10 < v1) {
            break;
        }
    }
    node->f14 = root->f14;
    node->f18 = root;
    root->f14->f18 = node;
    root->f14 = node;
    node->b0 = 1;
    node->b1 = 0;
    node->b2 = 0;
    node->key = (u16)key;
    node->key10 = key10;
    node->target = target;
    return node;
}
