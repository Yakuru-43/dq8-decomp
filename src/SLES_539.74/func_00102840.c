// range: 0x00102840 0x001029C0
// flags: -O4,p
#include "common.h"

struct Block {
    u32 pad0[5];      /* 0x00 */
    u32 f14;          /* 0x14 */
    char *base;       /* 0x18 */
    u8 pad1[0x104];   /* 0x1C */
    u128 q120[14];    /* 0x120 */
    u128 stash;       /* 0x200 */
    u32 pad1b[4];     /* 0x210 */
    u32 f220;         /* 0x220 */
    u32 f224;         /* 0x224 */
    s32 count;        /* 0x228 */
    u32 f22C;         /* 0x22C */
    s32 f230;         /* 0x230 */
    u32 n234;         /* 0x234 */
    u32 pad2[20];     /* 0x238 */
    u32 w288[16];     /* 0x288 */
};

struct Src {
    u32 pad0;
    s8 *flags;        /* 0x04 */
};

u32 func_00102840(struct Block *obj, struct Src *src) {
    u64 count;
    u64 f220;
    s32 flag40;
    u64 f224;
    u64 n234;
    char *end;
    u128 *ptr;
    u32 ret;
    s32 i;
    s32 j;

    f224 = obj->f224;
    f220 = obj->f220;
    count = obj->count;
    flag40 = *src->flags & 0x40;
    if (flag40 != 0) {
        n234 = obj->n234;
        end = obj->base + f224 + ((n234 * 4 + 15) & ~15);
        ptr = (u128 *)((u32)end + count * 16);
    } else {
        ptr = (u128 *)(obj->base + f224 + count * 16);
    }
    if (obj->f230 != 0) {
        ptr++;
    }
    ret = *(u32 *)ptr;
    if (obj->f230 == 0) {
        if (count == 9) {
            ptr--;
            count--;
            obj->stash = *ptr;
        }
    } else {
        ptr--;
        obj->stash = *ptr;
    }
    ptr -= count;
    for (i = 0; i < count; i++) {
        obj->q120[i] = *ptr++;
    }
    count = (s32)f220;
    obj->f14 = (u32)(obj->base + count);
    if (flag40 != 0) {
        u32 *pw = (u32 *)end - n234;

        for (j = 0; j < n234; j++) {
            obj->w288[j] = *pw++;
        }
    }
    return ret;
}
