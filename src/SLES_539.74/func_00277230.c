// range: 0x277230 0x277340
#include "common.h"

typedef struct {
    u32 pad0[1];
    void *field_4;
    u32 pad1[2];
    s32 field_10;
} ListEntry;

typedef struct {
    u32 pad0[3];
    void *next;
} ListNode;

typedef struct {
    u32 pad0[0x100 / 4];
    s32 field_100;
    void **field_104;
    ListEntry *field_108;
} Container;

extern void func_0014E500(s32, void *);

void func_00277230(s32 arg0, s32 arg1, Container *arg2) {
    s32 i;
    void **slot;
    ListNode *node;
    ListEntry *entry;
    s32 count;
    ListNode *next;

    if (arg2->field_108 != 0) {
        for (i = 0; i < arg2->field_100; i++) {
            slot = arg2->field_104 + i;
            node = (ListNode *)*slot;
            while (node != 0) {
                entry = arg2->field_108 + i;
                count = entry->field_10;
                next = (ListNode *)node->next;
                if (count > 0) {
                    entry->field_10 = count - 1;
                    *(ListNode **)((char *)entry->field_4 + (entry->field_10 << 2)) = node;
                }
                node = next;
            }
            *slot = 0;
        }
        return;
    }

    for (i = 0; i < arg2->field_100; i++) {
        slot = arg2->field_104 + i;
        node = (ListNode *)*slot;
        while (node != 0) {
            next = (ListNode *)node->next;
            func_0014E500(arg1, node);
            node = next;
        }
        *slot = 0;
    }
}
