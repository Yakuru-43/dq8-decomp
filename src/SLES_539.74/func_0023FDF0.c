// range: 0x23FDF0 0x23FE50
#include "common.h"

typedef struct TaggedDD8A0 {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TaggedDD8A0;

typedef struct NodeDD8A0 {
    /* 0x00 */ TaggedDD8A0 in;
    /* 0x08 */ s32 outType;
    /* 0x0C */ u32 out;
} NodeDD8A0;

extern f32 sqrtf(f32);

s32 func_0023FDF0(NodeDD8A0 *n, s32 kind) {
    f32 x;
    u32 out;

    if (kind != 2) {
        return 0;
    }
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
