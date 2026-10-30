// range: 0x14E640 0x14E700
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct AllocNode {
    /* 0x00 */ struct AllocNode *next;
    /* 0x04 */ struct AllocNode *prev;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 gap;
} AllocNode;

typedef struct AllocList {
    /* 0x00 */ u8 gap00[0x18];
    /* 0x18 */ AllocNode *first;
} AllocList;

AllocNode *func_0014E640(AllocList *list, u32 size, u32 align) {
    AllocNode *node = list->first;
    AllocNode *next;
    AllocNode *end;
    AllocNode *result;
    u32 need = size + align;
    s32 gap;
    u32 units;
    u32 rem;

    while ((next = node->next) != 0) {
        end = node + node->size;
        gap = next - end;
        if (gap >= need) {
            end->next = next;
            result = end + 1;
            node->next = end;
            units = (u32)result >> 4;
            end->prev = node;
            next = end->next;
            next->prev = end;
            end->size = need;
            rem = units % align;
            if (rem != 0) {
                result += align - rem;
            }
            gap = result - end;
            end->gap = gap;
            result[-1].gap = end->gap;
            return result;
        }
        node = next;
    }
    return 0;
}
