// range: 0x240280 0x240360
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
    s32 isFloat;
    Divisor div;
} Num;

typedef struct {
    s32 mode0;
    Pair *pair0;
    s32 mode1;
    Pair *pair1;
    s32 mode2;
    Pair *pair2;
    Num num[3];
} Norm;

s32 func_00240280(Norm *o, s32 n) {
    f32 d0;
    f32 d1;
    f32 d2;
    Num *nm;
    Pair *p;
    f32 *fp;
    f32 q;

    if (n != 6) {
        return 0;
    }
    nm = o->num;
    if (nm[0].isFloat == 0) {
        d0 = (f32)nm[0].div.i;
    } else {
        d0 = nm[0].div.f;
    }
    if (nm[1].isFloat == 0) {
        d1 = (f32)nm[1].div.i;
    } else {
        d1 = nm[1].div.f;
    }
    if (nm[2].isFloat == 0) {
        d2 = (f32)nm[2].div.i;
    } else {
        d2 = nm[2].div.f;
    }
    p = o->pair0;
    fp = &p->hi;
    q = p->hi + d0;
    if (o->mode0 == 3) {
        *fp = q;
    }
    p = o->pair1;
    fp = &p->hi;
    q = p->hi + d1;
    if (o->mode1 == 3) {
        *fp = q;
    }
    p = o->pair2;
    fp = &p->hi;
    q = p->hi + d2;
    if (o->mode2 == 3) {
        *fp = q;
    }
    return 1;
}
