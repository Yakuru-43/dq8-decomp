// range: 0x001DD900 0x001DDAA0
#include "common.h"

typedef struct TaggedDD900 {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TaggedDD900;

extern f32 func_0013D3E0(f32 *args);
extern f32 func_0013D340(f32 *args1, f32 *args2);

static inline f32 getDD900(TaggedDD900 *t) {
    if (t->tag == 0) {
        return (f32)t->bits;
    }
    return *(f32 *)&t->bits;
}

s32 func_001DD900(TaggedDD900 *n, s32 kind) {
    f32 args1[4];
    f32 args2[4];
    TaggedDD900 *t;
    TaggedDD900 *u;
    f32 r;

    switch (kind) {
    case 4:
        args1[0] = getDD900(n);
        t = n + 1;
        args1[1] = getDD900(t);
        args1[2] = getDD900(&n[2]);
        args1[3] = 1.0f;
        n += 3;
        r = func_0013D3E0(args1);
        break;
    case 7:
        args1[0] = getDD900(n);
        t = n + 1;
        args1[1] = getDD900(t);
        args1[2] = getDD900(&n[2]);
        args1[3] = 1.0f;
        t = n + 3;
        args2[0] = getDD900(t);
        u = t + 1;
        args2[1] = getDD900(u);
        args2[2] = getDD900(t + 2);
        args2[3] = 1.0f;
        n += 6;
        r = func_0013D340(args1, args2);
        break;
    default:
        return 0;
    }
    if (n->tag == 3) {
        *(f32 *)(n->bits + 4) = r;
    }
    return 1;
}
