// range: 0x370D40 0x370E00
#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ char pad_14[0x4];
} S_srcEntry; /* size 0x18 */

typedef struct {
    /* 0x00 */ S_srcEntry *src;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} S_dstEntry; /* size 0x1C */

typedef struct {
    /* 0x00 */ S_srcEntry *src_base;
    /* 0x04 */ S_dstEntry *dst_list;
    /* 0x08 */ char pad_08[0x8];
    /* 0x10 */ s32 unk_10;
} S_hdr;

void func_00370D20(s32 arg0, S_dstEntry *arg1);

void func_00370D40(s32 arg0, S_srcEntry *arg1, s32 arg2) {
    S_hdr *hdr = (S_hdr *)arg0;
    S_srcEntry *src;
    S_dstEntry *dst;

    hdr->src_base = arg1;
    dst = hdr->dst_list;
    src = arg1;
    while (src->unk_00 != 0) {
        dst->src = src;
        dst->unk_04 = src->unk_04;
        dst->unk_06 = src->unk_06;
        dst->unk_08 = src->unk_08;
        dst->unk_0A = src->unk_0A;
        dst->unk_0C = src->unk_0C;
        dst->unk_0E = src->unk_0E;
        dst->unk_10 = src->unk_10;
        dst->unk_12 = src->unk_12;
        func_00370D20(arg0, dst);
        dst = (S_dstEntry *)((char *)dst + 0x1C);
        src = (S_srcEntry *)((char *)src + 0x18);
    }
    dst->src = 0;
    hdr->unk_10 = arg2;
}
