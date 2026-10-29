// range: 0x1CCDF0 0x1CCE70
#include "common.h"

typedef struct Slot1CCDF0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ union { s32 i; f32 f; char *ptr; } v;
} Slot1CCDF0;

extern f32 func_0012A038(f32, f32);

s32 func_001CCDF0(Slot1CCDF0 *arg0) {
    f32 f1;
    f32 f2;
    f32 r;
    Slot1CCDF0 *t1;

    if (arg0[0].type == 0) {
        f1 = (f32)arg0[0].v.i;
    } else {
        f1 = arg0[0].v.f;
    }
    t1 = arg0 + 1;
    if (t1->type == 0) {
        f2 = (f32)t1->v.i;
    } else {
        f2 = t1->v.f;
    }
    r = func_0012A038(f1, f2);
    if (arg0[2].type == 3) {
        *(f32 *)(arg0[2].v.ptr + 4) = r;
    }
    return 1;
}
