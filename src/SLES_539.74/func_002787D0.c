// range: 0x2787D0 0x278880
#include "common.h"

struct Node {
    struct Node *next;
};

struct BucketList {
    s32 count;
    char pad[4];
    struct Node **buckets;
};

extern void func_001007A0(struct Node *node);
extern void func_00100780(void *block);

/* walks every chain of the table, releases each node, then the table itself */
void func_002787D0(struct BucketList *list) {
    struct Node *node;
    struct Node *next;
    s32 i;

    if (list->buckets == 0) {
        return;
    }
    for (i = 0; i < list->count; i = i + 1) {
        node = list->buckets[i];
        while (node != 0) {
            next = node->next;
            func_001007A0(node);
            node = next;
        }
        list->buckets[i] = 0;
    }
    func_00100780(list->buckets);
    list->buckets = 0;
    list->count = 0;
}
