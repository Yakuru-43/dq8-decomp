// range: 0x1BE460 0x1BE4A0
#include "common.h"

void func_00181510(s32 arg0);

typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ f32 f;
} FloatHolder;

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        FloatHolder *ph;
        s32 i;
    } value;
} TaggedInt;

s32 func_001BE460(TaggedInt *p) {
    s32 i = p->value.i;
    s32 v;

    if (p->type == 1) {
        v = (s32)*(f32 *)(i + 4);
    } else {
        v = i;
    }
    func_00181510(v);
    return 1;
}
