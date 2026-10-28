// range: 0x1BA630 0x1BA680
#include "common.h"

s32 func_001A2130(s32);

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ union {
        f32 f;
        s32 i;
    } value;
} TaggedInt;

s32 func_001BA630(TaggedInt *p) {
    s32 v;

    if (p->type == 1) {
        v = (s32)p->value.f;
    } else {
        v = p->value.i;
    }
    if (func_001A2130(v) == 0) {
        return 0;
    }
    return 1;
}
