// range: 0x1DD760 0x1DD810
#include "common.h"

typedef struct SlotFCB0 {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} SlotFCB0;

typedef struct NodeFCB0 {
    /* 0x00 */ SlotFCB0 in[3];
    /* 0x18 */ s32 outType;
    /* 0x1C */ u32 out;
} NodeFCB0;

extern s32 func_0013BD20(f32, f32, f32);

s32 func_001DD760(NodeFCB0 *n, s32 kind) {
    f32 x0;
    f32 x1;
    f32 x2;
    SlotFCB0 *p;
    s32 ret;
    u32 out;

    if (kind != 4) {
        return 0;
    }
    if (n->in[0].tag == 0) {
        x0 = (f32)n->in[0].bits;
    } else {
        x0 = *(f32 *)&n->in[0].bits;
    }
    p = n->in + 1;
    if (p->tag == 0) {
        x1 = (f32)p->bits;
    } else {
        x1 = *(f32 *)&p->bits;
    }
    p = n->in + 2;
    if (p->tag == 0) {
        x2 = (f32)p->bits;
    } else {
        x2 = *(f32 *)&p->bits;
    }
    ret = func_0013BD20(x0, x1, x2);
    if (n->outType == 3) {
        out = n->out;
        *(s32 *)(out + 4) = ret;
    }
    return 1;
}
