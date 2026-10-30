// range: 0x1B87D0 0x1B8800
#include "common.h"

typedef struct {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
} TaggedValue;

extern M2C_UNK D_00411DA4 __attribute__((section(".data")));

s32 func_001B87D0(TaggedValue *arg0) {
    s32 result;

    result = (arg0->tag == 1) ? (s32)arg0->val.f : arg0->val.i;
    D_00411DA4 = result;
    return 1;
}
