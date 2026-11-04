// range: 0x001BC430 0x001BC480
#include "common.h"

typedef struct Tagged1BC430 {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} Tagged1BC430;

typedef struct Node1BC430 {
    /* 0x00 */ Tagged1BC430 in;
    /* 0x08 */ s32 outType;
    /* 0x0C */ u32 out;
} Node1BC430;

extern f32 sqrtf(f32);

s32 func_001BC430(Node1BC430 *n) {
    f32 x;
    u32 out;

    if (n->in.tag == 0) {
        x = (f32)n->in.bits;
    } else {
        x = *(f32 *)&n->in.bits;
    }
    x = sqrtf(x);
    if (n->outType == 3) {
        out = n->out;
        *(f32 *)(out + 4) = x;
    }
    return 1;
}
