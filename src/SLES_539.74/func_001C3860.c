// range: 0x001C3860 0x001C3940
#include "common.h"

typedef union {
    /* 0x00 */ s32 i;
    /* 0x04 */ f32 f;
} ValC3860;

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ ValC3860 val;
} TaggedC3860;

void func_00172D10(s32, s32, s32, s32);

s32 func_001C3860(TaggedC3860 *arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    TaggedC3860 *in;

    if (arg0->type == 1) {
        a = (s32)arg0->val.f;
    } else {
        a = arg0->val.i;
    }
    in = arg0 + 1;
    if (in->type == 1) {
        b = (s32)in->val.f;
    } else {
        b = in->val.i;
    }
    in = arg0 + 2;
    if (in->type == 1) {
        c = (s32)in->val.f;
    } else {
        c = in->val.i;
    }
    switch (arg1) {
    case 3:
        func_00172D10(a, b, c, 0);
        break;
    case 4:
        if (arg0[3].type == 1) {
            d = (s32)arg0[3].val.f;
        } else {
            d = arg0[3].val.i;
        }
        func_00172D10(a, b, c, d);
        break;
    }
    return 1;
}
