// range: 0x23FD60 0x23FDF0
#include "common.h"

typedef struct {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TaggedFD60;

typedef struct {
    /* 0x00 */ TaggedFD60 in[2];
    /* 0x10 */ s32 outType;
    /* 0x14 */ u32 out;
} NodeFD60;

extern f32 func_0012A038(f32, f32);

s32 func_0023FD60(NodeFD60 *n, s32 kind) {
    f32 x;
    f32 y;
    u32 out;
    TaggedFD60 *t;

    if (kind != 3) {
        return 0;
    }
    if (n->in[0].tag == 0) {
        x = (f32)n->in[0].bits;
    } else {
        x = *(f32 *)&n->in[0].bits;
    }
    t = n->in + 1;
    if (t->tag == 0) {
        y = (f32)t->bits;
    } else {
        y = *(f32 *)&t->bits;
    }
    x = func_0012A038(x, y);
    if (n->outType == 3) {
        out = n->out;
        *(f32 *)(out + 4) = x;
    }
    return 1;
}
