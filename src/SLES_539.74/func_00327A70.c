// range: 0x327A70 0x327B10
#include "common.h"

struct Stats {
    u8 pad[0x40];
    f32 vals[2][7];
};

extern s32 func_00342840(void);

f32 func_00327A70(s32 idx, s32 mode) {
    struct Stats *tbl;
    s32 i;
    f32 v;

    i = idx;
    tbl = (struct Stats *)func_00342840();
    if (i < 0) {
        i = 0;
    }
    if (7 <= i) {
        i = 6;
    }
    v = tbl->vals[mode == 0][i];
    if (v < 1.0f) {
        v = 1.0f;
    }
    return v;
}
