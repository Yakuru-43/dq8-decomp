// range: 0x140540 0x140580
#include "common.h"

typedef struct {
    /* 0000 */ char pad_0[0x3BA4];
    /* 3BA4 */ s32 count;
} Obj;

void func_001419A0(Obj *, s32, f32);      /* extern */

s32 func_00140540(Obj *o, s32 idx) {
    if (idx >= 0) {
        if (idx < o->count) {
            func_001419A0(o, idx, 0.0f);
            return 1;
        }
    }
    return 0;
}
