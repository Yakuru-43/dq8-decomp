// range: 0x23B710 0x23B820
// best attempt (score 32) for func_0023B710 — see func_0023B710.md
#include "common.h"

extern s32 D_003E0B24;

typedef union Val23B710 {
    /* 0x00 */ s32 i;
    /* 0x04 */ f32 f;
} Val23B710;

typedef struct Tagged23B710 {
    /* 0x00 */ s32 type;
    /* 0x04 */ Val23B710 v;
} Tagged23B710;

s32 func_0023B710(char *arg0, s32 arg1) {
    s32 count;
    s32 start;
    f32 val3;
    f32 val2;
    f32 val1;
    Tagged23B710 *tv;
    s32 node;
    s32 limit;
    s32 i;

    count = 1;
    if (*(s32 *)arg0 == 1) {
        start = (s32)*(f32 *)(arg0 + 4);
    } else {
        start = *(s32 *)(arg0 + 4);
    }
    tv = (Tagged23B710 *)(arg0 + 8);
    if (*(s32 *)(arg0 + 8) == 0) {
        val1 = (f32)tv->v.i;
    } else {
        val1 = tv->v.f;
    }
    tv = (Tagged23B710 *)(arg0 + 0x10);
    if (*(s32 *)(arg0 + 0x10) == 0) {
        val2 = (f32)tv->v.i;
    } else {
        val2 = tv->v.f;
    }
    tv = (Tagged23B710 *)(arg0 + 0x18);
    if (*(s32 *)(arg0 + 0x18) == 0) {
        val3 = (f32)tv->v.i;
    } else {
        val3 = tv->v.f;
    }
    if (arg1 >= 5) {
        if (*(s32 *)(arg0 + 0x20) == 1) {
            count = (s32)*(f32 *)(arg0 + 0x24);
        } else {
            count = *(s32 *)(arg0 + 0x24);
        }
    }
    i = start;
    limit = start + count;
    while (i < limit) {
        if (D_003E0B24 != 0 && i < *(s32 *)(D_003E0B24 + 0x2C)) {
            node = *(s32 *)(D_003E0B24 + 0x28) + i * 272;
        } else {
            node = 0;
        }
        if (node == 0) {
            return 0;
        }
        *(f32 *)(node + 0xB8) = val1;
        i++;
        *(f32 *)(node + 0xBC) = val2;
        *(f32 *)(node + 0xC0) = val3;
    }
    return 1;
}
