// range: 0x1C14B0 0x1C1530
#include "common.h"

M2C_UNK func_001AC490(void *, s32, f32, f32, f32);
extern M2C_UNK D_00411ED0 __attribute__((section(".data")));

typedef struct {
    /* 0x0 */ s32 tag;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

s32 func_001C14B0(Tagged *arg0) {
    f32 f1;
    f32 f2;
    f32 f3;
    f32 tmp;
    s32 a1;
    Tagged *t1;
    Tagged *t2;

    if (arg0[0].tag == 1) {
        tmp = arg0[0].v.f;
        a1 = (s32)tmp;
    } else {
        a1 = arg0[0].v.i;
    }
    t1 = arg0 + 1;
    if (t1->tag == 0) {
        f1 = (f32)t1->v.i;
    } else {
        f1 = t1->v.f;
    }
    t2 = arg0 + 2;
    if (t2->tag == 0) {
        f2 = (f32)t2->v.i;
    } else {
        f2 = t2->v.f;
    }
    f3 = (arg0[3].tag == 0) ? (f32)arg0[3].v.i : arg0[3].v.f;
    return func_001AC490(&D_00411ED0, a1, f1, f2, f3);
}
