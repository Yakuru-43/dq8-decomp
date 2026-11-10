// range: 0x2401A0 0x240280
#include "common.h"

typedef union Value {
    s32 i;
    f32 f;
} Value;

typedef struct {
    s32 isFloat;
    Value val;
} Tagged;

typedef struct {
    f32 lo;
    f32 hi;
} Pair;

typedef struct {
    s32 mode0;
    Pair *pair0;
    s32 mode1;
    Pair *pair1;
    s32 mode2;
    Pair *pair2;
    Tagged tags[3];
} Norm;

s32 func_002401A0(Norm *o, s32 n) {
    f32 d0;
    f32 d1;
    f32 d2;
    Tagged *t;
    Pair *p;
    f32 *fp;
    f32 q;

    if (n != 6) {
        return 0;
    }
    t = o->tags;
    if (t->isFloat == 0) {
        d0 = (f32)t->val.i;
    } else {
        d0 = t->val.f;
    }
    if (t[1].isFloat == 0) {
        d1 = (f32)t[1].val.i;
    } else {
        d1 = t[1].val.f;
    }
    if (t[2].isFloat == 0) {
        d2 = (f32)t[2].val.i;
    } else {
        d2 = t[2].val.f;
    }
    p = o->pair0;
    fp = &p->hi;
    q = p->hi - d0;
    if (o->mode0 == 3) {
        *fp = q;
    }
    p = o->pair1;
    fp = &p->hi;
    q = p->hi - d1;
    if (o->mode1 == 3) {
        *fp = q;
    }
    p = o->pair2;
    fp = &p->hi;
    q = p->hi - d2;
    if (o->mode2 == 3) {
        *fp = q;
    }
    return 1;
}
