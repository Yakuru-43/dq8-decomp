// range: 0x0014E360 0x0014E500
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct BufNode14E360 {
    /* 0x00 */ struct BufNode14E360 *next;
    /* 0x04 */ struct BufNode14E360 *prev;
    /* 0x08 */ s32 size;
    /* 0x0C */ s32 size2;
} BufNode14E360;

typedef struct Buf14E360 {
    /* 0x00 */ u8 gap00[0x18];
    /* 0x18 */ BufNode14E360 *list;
    /* 0x1C */ u8 gap1C[0x28 - 0x1C];
    /* 0x28 */ char *alloc_end;
    /* 0x2C */ u8 gap2C[8];
    /* 0x34 */ s32 tail;
    /* 0x38 */ BufNode14E360 *cur;
} Buf14E360;

char *func_0014E360(Buf14E360 *buf, s32 mode, s32 min, s32 size)
{
    BufNode14E360 *node;
    char *found;
    BufNode14E360 *found_node;
    u32 best;
    u32 gap;
    char *end;
    BufNode14E360 *next;
    s32 units;
    u32 limit;

    units = size / 16;
    buf->cur = 0;
    node = buf->list;
    limit = min + units;
    if (node == 0) {
        return 0;
    }
    found = 0;
    found_node = 0;
    best = 0;
    while ((next = node->next) != 0) {
        end = (char *)node + node->size * 16;
        gap = (u32)((s32)((char *)next - end) / 16);
        if (mode == 1) {
            if (gap > 1) {
                found = end;
                found_node = node;
                break;
            }
        }
        if (mode == 2) {
            if (best < gap) {
                found = end;
                found_node = node;
                best = gap;
            }
        }
        if (mode == 3) {
            if (limit < gap) {
                found = end;
                found_node = node;
                break;
            }
        }
        node = next;
    }
    if (found == 0) {
        return 0;
    }
    buf->cur = (BufNode14E360 *)found;
    next = found_node->next;
    buf->cur->next = next;
    found_node->next = buf->cur;
    buf->cur->prev = found_node;
    buf->cur->next->prev = buf->cur;
    node = buf->cur;
    end = (char *)node + 0x10;
    gap = ((u32)end >> 4) % (u32)units;
    if (gap != 0) {
        end += (units - gap) << 4;
    }
    node->size2 = (s32)(end - (char *)node) / 16;
    *(s32 *)(end - 4) = node->size2;
    buf->cur->size = (s32)(end - (char *)buf->cur) / 16;
    buf->alloc_end = end;
    buf->tail = (s32)((char *)buf->cur->next - end) / 16;
    return end;
}
