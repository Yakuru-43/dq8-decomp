// range: 0x327810 0x327930
#include "common.h"

struct Stats {
    u8 pad[0x40];
    f32 vals[2][7];
};

extern s32 func_00342840(void);

f32 func_00327810(s32 type, s32 idx, s32 mode) {
    struct Stats *tbl;
    s32 i;
    f32 rate;
    f32 v;

    tbl = (struct Stats *)func_00342840();
    i = idx;
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
    rate = 1.0f;
    switch (type) {
    case 0x1A8:
        rate = 2.0f;
        break;
    case 0x4E:
        rate = 2.0f * v;
        break;
    case 0x4F:
        rate = 5.0f * v;
        break;
    case 0x50:
        rate = 10.0f * v;
        break;
    }
    return 1.0f / rate;
}
