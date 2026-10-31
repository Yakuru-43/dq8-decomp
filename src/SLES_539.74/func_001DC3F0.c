// range: 0x1DC3F0 0x1DC430
#include "common.h"

void func_0017AD80(s32 arg0);

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        f32 f;
        s32 i;
    } value;
} TaggedInt;

s32 func_001DC3F0(TaggedInt *p) {
    s32 v;

    if (p->type == 1) {
        v = (s32)p->value.f;
    } else {
        v = p->value.i;
    }
    func_0017AD80(v);
    return 1;
}
