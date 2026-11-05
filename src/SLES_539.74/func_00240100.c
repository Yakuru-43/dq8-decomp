// range: 0x240100 0x2401A0
#include "common.h"

typedef union Divisor {
    s32 i;
    f32 f;
} Divisor;

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
    s32 isFloat;
    Divisor div;
} Norm;

s32 func_00240100(Norm *o, s32 n) {
    f32 d;
    Pair *p;
    f32 *fp;
    f32 q;

    if (n != 4) {
        return 0;
    }
    if (o->isFloat == 0) {
        d = (f32)o->div.i;
    } else {
        d = o->div.f;
    }
    p = o->pair0;
    fp = &p->hi;
    q = p->hi * d;
    if (o->mode0 == 3) {
        *fp = q;
    }
    p = o->pair1;
    fp = &p->hi;
    q = p->hi * d;
    if (o->mode1 == 3) {
        *fp = q;
    }
    p = o->pair2;
    fp = &p->hi;
    q = p->hi * d;
    if (o->mode2 == 3) {
        *fp = q;
    }
    return 1;
}
