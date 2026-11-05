// range: 0x0016CEE0 0x0016CFA0
// Tests a float field against 1.0, scaled by a virtual on the object (vptr at
// +0x1B0, slot 0x1C) when +0x1DC is set; the mode picks which side of 1.0 wins.
#include "common.h"

extern "C" {

struct Object {
    u8 pad0[0x1B0];                  /* 0x00 */
    virtual s32 v0();
    virtual s32 v1();
    virtual s32 v2();
    virtual s32 v3();
    virtual s32 v4();
    virtual f32 v5();                /* vtable slot 0x1C */
};

struct Unit : Object {
    u8 pad1B4[0x1DC - 0x1B4];        /* 0xB4 */
    s32 n_1DC;                       /* 0x1DC */
    u8 pad1E0[0x448 - 0x1E0];        /* 0x1E0 */
    f32 f_448;                       /* 0x448 */
};

s32 func_0016CEE0(Unit *unit, s32 arg1, s32 mode) {
    f32 v;

    if (unit == 0) {
        return 1;
    }
    if (0 < mode) {
        v = unit->f_448;
        if (unit->n_1DC != 0) {
            v = v * unit->v5();
        }
        if (mode == 1) {
            if (v < 1.0f) {
                return 1;
            }
        }
        if (mode == 2) {
            if (!(v < 1.0f)) {
                return 1;
            }
        }
    } else {
        return 0;
    }
    return 0;
}

}
