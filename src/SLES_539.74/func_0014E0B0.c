// range: 0x0014E0B0 0x0014E130
#include "common.h"

typedef struct AlignE0B0 {
    /* 0x00 */ u8 gap00[0x20];
    /* 0x20 */ s32 locked;
    /* 0x24 */ u8 gap24[4];
    /* 0x28 */ s32 base;
    /* 0x2C */ s32 index;
    /* 0x30 */ u8 gap30[4];
    /* 0x34 */ s32 limit;
} AlignE0B0;

void func_0014E0B0(AlignE0B0 *a) {
    s32 mis;
    s32 d;
    s32 n;

    if (a->locked) {
        return;
    }
    mis = (a->base + (a->index << 4)) & 0x3F;
    if (mis != 0) {
        d = 0x40 - mis;
        n = d / 16;
        a->index = a->index + n;
    }
    if (a->index >= a->limit) {
        a->index = a->limit;
    }
}
