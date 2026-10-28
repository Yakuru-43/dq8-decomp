// range: 0x1B3F70 0x1B3FB0
#include "common.h"

void func_00304150(s32 mode);

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        f32 f;
        s32 i;
    } value;
} TaggedInt;

s32 func_001B3F70(TaggedInt *p) {
    s32 v;

    if (p->type == 1) {
        v = (s32)p->value.f;
    } else {
        v = p->value.i;
    }
    func_00304150(v);
    return 1;
}
