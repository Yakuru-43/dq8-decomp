// range: 0x1BD580 0x1BD5B0
#include "common.h"

typedef struct {
    s32 tag;
    union {
        s32 i;
        f32 f;
    } val;
} TaggedValue;

extern M2C_UNK D_00411D7C __attribute__((section(".data")));

s32 func_001BD580(TaggedValue *arg0) {
    s32 result;

    result = (arg0->tag == 1) ? (s32)arg0->val.f : arg0->val.i;
    D_00411D7C = result;
    return 1;
}
