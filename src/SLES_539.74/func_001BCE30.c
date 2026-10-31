// range: 0x1BCE30 0x1BCF90
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

void func_0013B720(f32 *, f32 *);

static inline f32 TaggedValue_GetFloat(TaggedValue *t) {
    if (t->tag == 0) {
        return (f32)t->val.i;
    }
    return t->val.f;
}

s32 func_001BCE30(Transform *t, s32 mode) {
    f32 res[4];
    OutSlot *sl;
    TaggedValue *p;
    TaggedValue *q;
    f32 val;

    switch (mode) {
    case 3:
        res[0] = *(f32 *)(t->out[0].ptr + 4);
        res[1] = *(f32 *)(t->out[1].ptr + 4);
        res[2] = *(f32 *)(t->out[2].ptr + 4);
        res[3] = 1.0f;
        break;
    case 6:
        p = t->a;
        res[0] = TaggedValue_GetFloat(p);
        q = p + 1;
        res[1] = TaggedValue_GetFloat(q);
        res[2] = TaggedValue_GetFloat(&p[2]);
        res[3] = 1.0f;
        break;
    default:
        return 0;
    }
    func_0013B720(res, res);
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
