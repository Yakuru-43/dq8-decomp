// range: 0x0014E570 0x0014E640
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct BlkE570 {
    char *data;           /* 0x0 */
    struct BlkE570 *next; /* 0x4 */
    s32 size16;           /* 0x8 */
    s32 count0C;          /* 0xC */
} BlkE570;

typedef struct PoolE570 {
    u8 gap00[0x1C];
    BlkE570 *list1C; /* 0x1C */
} PoolE570;

char *func_0014E570(PoolE570 *pool, s32 arg1, s32 arg2) {
    BlkE570 *blk;
    BlkE570 *hdr;
    char *data;
    char *end;
    char *end16;
    s32 free16;
    s32 need;
    u32 n16;
    s32 rem;

    need = arg1 + arg2;
    blk = pool->list1C->next;
    while (blk != 0) {
        data = blk->data;
        end16 = (char *)blk + (blk->size16 << 4);
        free16 = (data - end16) / 16;
        if ((u32)free16 >= (u32)need) {
            hdr = (BlkE570 *)(data - (need << 4));
            hdr->data = data;
            end = (char *)hdr + 0x10;
            blk->data = (char *)hdr;
            n16 = (u32)end >> 4;
            hdr->next = blk;
            ((BlkE570 *)hdr->data)->next = hdr;
            hdr->size16 = need;
            rem = n16 % arg2;
            if (rem != 0) {
                end += (arg2 - rem) << 4;
            }
            hdr->count0C = (end - (char *)hdr) / 16;
            *(s32 *)(end - 4) = hdr->count0C;
            return end;
        }
        blk = blk->next;
    }
    return 0;
}
