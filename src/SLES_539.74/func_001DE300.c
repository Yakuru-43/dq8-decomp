// range: 0x001DE300 0x001DE3B0
#include "common.h"

typedef struct SlotDE300 {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} SlotDE300;

typedef struct NodeDE300 {
    /* 0x00 */ SlotDE300 out[3];
    /* 0x18 */ SlotDE300 in[3];
} NodeDE300;

s32 func_001DE300(NodeDE300 *n, s32 kind) {
    SlotDE300 *p;
    SlotDE300 *q;
    f32 x0;
    f32 x1;
    f32 x2;

    p = n->in;
    if (p[0].tag == 0) {
        x0 = (f32)p[0].bits;
    } else {
        x0 = *(f32 *)&p[0].bits;
    }
    q = p + 1;
    if (q->tag == 0) {
        x1 = (f32)q->bits;
    } else {
        x1 = *(f32 *)&q->bits;
    }
    if (p[2].tag == 0) {
        x2 = (f32)p[2].bits;
    } else {
        x2 = *(f32 *)&p[2].bits;
    }
    p = n->out;
    if (p->tag == 3) {
        *(f32 *)(p->bits + 4) = x0;
    }
    p = n->out + 1;
    if (p->tag == 3) {
        *(f32 *)(p->bits + 4) = x1;
    }
    if (n->out[2].tag == 3) {
        *(f32 *)(n->out[2].bits + 4) = x2;
    }
    return 1;
}
