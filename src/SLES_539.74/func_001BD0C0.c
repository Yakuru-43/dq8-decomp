// range: 0x1BD0C0 0x1BD100
#include "common.h"

void func_00167FC0(s32 arg0);

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        f32 f;
        s32 i;
    } value;
} TaggedInt;

s32 func_001BD0C0(TaggedInt *p) {
    s32 v;

    if (p->type == 1) {
        v = (s32)p->value.f;
    } else {
        v = p->value.i;
    }
    func_00167FC0(v);
    return 1;
}
