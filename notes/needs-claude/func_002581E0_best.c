// range: 0x2581E0 0x2582B0
#include "common.h"

extern s32 D_003E0C1C;
extern s32 D_003E0C20;

typedef struct LItem {
    u8 pad2[0x1C];
    s32 idx;
} LItem;

typedef struct LNode {
    struct LNode *next;
    u8 pad1[0x0C];
    LItem item;
} LNode;

s32 func_002581E0(s32 mode, s32 type) {
    LNode *node;
    LItem *item;
    s32 count;
    s32 sum;
    s32 ret;

    node = (LNode *)D_003E0C1C;
    if (node == 0) {
        goto none;
    }
    if (D_003E0C20 == 0) {
        goto none;
    }
    ret = 1;
    goto merged;
none:
    ret = 0;
merged:
    if (ret == 0) {
        return 0;
    }
    count = 0;
    sum = 0;
    while (node != 0) {
        item = &node->item;
        if (*(s32 *)((u8 *)node + 0x28) == type) {
            if (mode == 1) {
                sum += *(s32 *)((u8 *)D_003E0C20 + item->idx * 1936 + 0x4D8);
            }
            count++;
        }
        node = node->next;
    }
    ret = 1;
    if (mode != 1) {
        return count;
    }
    ret = sum / 1024;
    if (0 < count) {
        ret++;
    }
    return ret;
}
