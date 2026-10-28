// range: 0x1B9EB0 0x1B9EF0
#include "common.h"

void func_002BA7E0(s32 arg0);

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        f32 f;
        s32 i;
    } value;
} TaggedInt;

s32 func_001B9EB0(TaggedInt *p) {
    s32 v;

    if (p->type == 1) {
        v = (s32)p->value.f;
    } else {
        v = p->value.i;
    }
    func_002BA7E0(v);
    return 1;
}
