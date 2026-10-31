// range: 0x001C6BA0 0x001C6C70
#include "common.h"

typedef struct {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
} TaggedValue;

M2C_UNK func_001A6D40(s32, f32, f32, f32, f32, s32, s32);
extern s32 D_003E06F4;

static inline f32 TaggedValue_GetFloat(TaggedValue *t) {
    if (t->tag == 0) {
        return (f32)t->val.i;
    }
    return t->val.f;
}

static inline s32 TaggedValue_GetInt(TaggedValue *t) {
    if (t->tag == 1) {
        return (s32)t->val.f;
    }
    return t->val.i;
}

s32 func_001C6BA0(TaggedValue *arg0) {
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x5;
    s32 x3;
    s32 x4;
    TaggedValue *t;

    x0 = TaggedValue_GetFloat(&arg0[0]);
    t = &arg0[1];
    x1 = TaggedValue_GetFloat(t);
    t = &arg0[2];
    x2 = TaggedValue_GetFloat(t);
    t = &arg0[3];
    x3 = TaggedValue_GetInt(t);
    t = &arg0[4];
    x4 = TaggedValue_GetInt(t);
    x5 = TaggedValue_GetFloat(&arg0[5]);
    func_001A6D40(D_003E06F4, x0, x1, x2, x5, x3, x4);
    return 1;
}
