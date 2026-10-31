// range: 0x1BCC30 0x1BCE30
#include "common.h"

typedef struct {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
} TaggedValue;

typedef struct {
    s32 type;
    char *ptr;
} OutSlot;

typedef struct {
    /* 0x00 */ OutSlot out[3];
    /* 0x18 */ TaggedValue a[3];
    /* 0x30 */ TaggedValue b[3];
} Transform;

void func_0013B7B0(f32 *, f32 *, f32 *);

static inline f32 TaggedValue_GetFloat(TaggedValue *t) {
    if (t->tag == 0) {
        return (f32)t->val.i;
    }
    return t->val.f;
}

s32 func_001BCC30(Transform *t, s32 mode) {
    f32 res[4];
    f32 va[4];
    f32 vb[4];
    OutSlot *sl;
    TaggedValue *p;
    TaggedValue *q;
    f32 val;

    switch (mode) {
    case 6:
        va[0] = *(f32 *)(t->out[0].ptr + 4);
        va[1] = *(f32 *)(t->out[1].ptr + 4);
        va[2] = *(f32 *)(t->out[2].ptr + 4);
        va[3] = 1.0f;
        p = t->a;
        vb[0] = TaggedValue_GetFloat(p);
        q = p + 1;
        vb[1] = TaggedValue_GetFloat(q);
        vb[2] = TaggedValue_GetFloat(&p[2]);
        vb[3] = 1.0f;
        break;
    case 9:
        p = t->a;
        va[0] = TaggedValue_GetFloat(p);
        q = p + 1;
        va[1] = TaggedValue_GetFloat(q);
        va[2] = TaggedValue_GetFloat(&p[2]);
        va[3] = 1.0f;
        p = t->b;
        vb[0] = TaggedValue_GetFloat(p);
        q = p + 1;
        vb[1] = TaggedValue_GetFloat(q);
        vb[2] = TaggedValue_GetFloat(&p[2]);
        vb[3] = 1.0f;
        break;
    default:
        return 0;
    }
    func_0013B7B0(res, va, vb);
    if (t->out[0].type == 3) {
        *(f32 *)(t->out[0].ptr + 4) = res[0];
    }
    val = res[1];
    sl = &t->out[1];
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = val;
    }
    val = res[2];
    if (t->out[2].type == 3) {
        *(f32 *)(t->out[2].ptr + 4) = val;
    }
    return 1;
}
