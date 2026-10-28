// range: 0x1BCA30 0x1BCC30
#include "common.h"

void func_0013B7D0(f32 *, f32 *, f32 *);

typedef union {
    f32 f;
    s32 i;
} TaggedF;

typedef struct {
    s32 flag;
    TaggedF value;
} TaggedSlot;

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *p0;
    /* 0x08 */ s32 flag0;
    /* 0x0C */ char *p1;
    /* 0x10 */ s32 flag1;
    /* 0x14 */ char *p2;
    /* 0x18 */ TaggedSlot a[3];
    /* 0x30 */ TaggedSlot b[3];
} Transform;

s32 func_001BCA30(Transform *t, s32 mode) {
    f32 out[4];
    f32 va[4];
    f32 vb[4];

    switch (mode) {
    case 6:
        va[0] = *(f32 *)(t->p0 + 4);
        va[1] = *(f32 *)(t->p1 + 4);
        va[2] = *(f32 *)(t->p2 + 4);
        va[3] = 1.0f;
        vb[0] = t->a[0].flag ? t->a[0].value.f : (f32)t->a[0].value.i;
        vb[1] = t->a[1].flag ? t->a[1].value.f : (f32)t->a[1].value.i;
        vb[2] = t->a[2].flag ? t->a[2].value.f : (f32)t->a[2].value.i;
        vb[3] = 1.0f;
        break;
    case 9:
        va[0] = t->a[0].flag ? t->a[0].value.f : (f32)t->a[0].value.i;
        va[1] = t->a[1].flag ? t->a[1].value.f : (f32)t->a[1].value.i;
        va[2] = t->a[2].flag ? t->a[2].value.f : (f32)t->a[2].value.i;
        va[3] = 1.0f;
        vb[0] = t->b[0].flag ? t->b[0].value.f : (f32)t->b[0].value.i;
        vb[1] = t->b[1].flag ? t->b[1].value.f : (f32)t->b[1].value.i;
        vb[2] = t->b[2].flag ? t->b[2].value.f : (f32)t->b[2].value.i;
        vb[3] = 1.0f;
        break;
    default:
        return 0;
    }
    func_0013B7D0(out, va, vb);
    if (t->type == 3) {
        *(f32 *)(t->p0 + 4) = out[0];
    }
    if (t->flag0 == 3) {
        *(f32 *)(t->p1 + 4) = out[1];
    }
    if (t->flag1 == 3) {
        *(f32 *)(t->p2 + 4) = out[2];
    }
    return 1;
}
