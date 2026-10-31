// range: 0x001DE1A0 0x001DE300
#include "common.h"

typedef struct SlotDE1A0 {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} SlotDE1A0;

typedef struct NodeDE1A0 {
    /* 0x00 */ SlotDE1A0 out[3];
    /* 0x18 */ SlotDE1A0 in[3];
} NodeDE1A0;

extern void func_0013B720(f32 *, f32 *);

s32 func_001DE1A0(NodeDE1A0 *n, s32 kind) {
    f32 buf[4];
    SlotDE1A0 *p;
    SlotDE1A0 *q;
    f32 x0;
    f32 x1;
    f32 x2;

    switch (kind) {
    case 3:
        buf[0] = *(f32 *)(n->out[0].bits + 4);
        buf[1] = *(f32 *)(n->out[1].bits + 4);
        buf[2] = *(f32 *)(n->out[2].bits + 4);
        buf[3] = 1.0f;
        break;
    case 6:
        p = n->in;
        if (p->tag == 0) {
            x0 = (f32)p->bits;
        } else {
            x0 = *(f32 *)&p->bits;
        }
        buf[0] = x0;
        q = p + 1;
        if (q->tag == 0) {
            x1 = (f32)q->bits;
        } else {
            x1 = *(f32 *)&q->bits;
        }
        buf[1] = x1;
        if (p[2].tag == 0) {
            x2 = (f32)p[2].bits;
        } else {
            x2 = *(f32 *)&p[2].bits;
        }
        buf[2] = x2;
        buf[3] = 1.0f;
        break;
    default:
        return 0;
    }
    func_0013B720(buf, buf);
    if (n->out[0].tag == 3) {
        x0 = buf[0];
        *(f32 *)(n->out[0].bits + 4) = x0;
    }
    x1 = buf[1];
    p = n->out + 1;
    if (p->tag == 3) {
        *(f32 *)(p->bits + 4) = x1;
    }
    x2 = buf[2];
    if (n->out[2].tag == 3) {
        *(f32 *)(n->out[2].bits + 4) = x2;
    }
    return 1;
}
