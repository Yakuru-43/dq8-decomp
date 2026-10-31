// Best draft for func_001DDFA0 (score 82, 500/512) — NOT verified, do not build with this.
// range: 0x1DDFA0 0x1DE1A0
#include "common.h"

void func_0013B7B0(f32 *, f32 *, f32 *);

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

s32 func_001DDFA0(Transform *t, s32 mode) {
    f32 out[4];
    f32 va[4];
    f32 vb[4];
    TaggedSlot *s;
    f32 x;

    switch (mode) {
    default:
        return 0;
    case 6:
        va[0] = *(f32 *)(t->p0 + 4);
        va[1] = *(f32 *)(t->p1 + 4);
        va[2] = *(f32 *)(t->p2 + 4);
        va[3] = 1.0f;
        s = t->a;
        if (!s[0].flag) { x = (f32)s[0].value.i; } else { x = s[0].value.f; }
        vb[0] = x;
        if (!s[1].flag) { x = (f32)s[1].value.i; } else { x = s[1].value.f; }
        vb[1] = x;
        if (!s[2].flag) { x = (f32)s[2].value.i; } else { x = s[2].value.f; }
        vb[2] = x;
        vb[3] = 1.0f;
        break;
    case 9:
        s = t->a;
        if (!s[0].flag) { x = (f32)s[0].value.i; } else { x = s[0].value.f; }
        va[0] = x;
        if (!s[1].flag) { x = (f32)s[1].value.i; } else { x = s[1].value.f; }
        va[1] = x;
        if (!s[2].flag) { x = (f32)s[2].value.i; } else { x = s[2].value.f; }
        va[2] = x;
        va[3] = 1.0f;
        s = t->b;
        if (!s[0].flag) { x = (f32)s[0].value.i; } else { x = s[0].value.f; }
        vb[0] = x;
        if (!s[1].flag) { x = (f32)s[1].value.i; } else { x = s[1].value.f; }
        vb[1] = x;
        if (!s[2].flag) { x = (f32)s[2].value.i; } else { x = s[2].value.f; }
        vb[2] = x;
        vb[3] = 1.0f;
        break;
    }
    func_0013B7B0(out, va, vb);
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
