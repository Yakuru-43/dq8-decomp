// range: 0x1C67B0 0x1C6850
#include "common.h"

typedef struct {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
} TaggedValue;

M2C_UNK func_001A6450(s32, f32 *, s32);
extern s32 D_003E06F4;

static inline f32 TaggedValue_GetFloat(TaggedValue *t) {
    if (t->tag == 0) {
        return (f32)t->val.i;
    }
    return t->val.f;
}

s32 func_001C67B0(TaggedValue *arg0) {
    f32 buf[4];
    s32 a2;
    TaggedValue *t;

    buf[0] = TaggedValue_GetFloat(&arg0[0]);
    t = &arg0[1];
    buf[1] = TaggedValue_GetFloat(t);
    t = &arg0[2];
    buf[2] = TaggedValue_GetFloat(t);
    buf[3] = 0.0f;
    if (arg0[3].tag == 1) {
        a2 = (s32)arg0[3].val.f;
    } else {
        a2 = arg0[3].val.i;
    }
    func_001A6450(D_003E06F4, buf, a2);
    return 1;
}
