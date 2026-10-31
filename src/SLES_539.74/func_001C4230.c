// range: 0x1C4230 0x1C4270
#include "common.h"

void func_00176500(s32 arg0);

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        f32 f;
        s32 i;
    } value;
} TaggedInt;

s32 func_001C4230(TaggedInt *p) {
    s32 v;

    if (p->type == 1) {
        v = (s32)p->value.f;
    } else {
        v = p->value.i;
    }
    func_00176500(v);
    return 1;
}
